#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <fstream>
#include <iostream>

#include "expatmodelparser.hh"
#include "modelhandler.hh"

#include "tree/tree_util.hh"

using namespace std;

void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end)
{
    if(!tr.is_valid(it)) return;
    int rootdepth=tr.depth(it);
    while(it!=end) {
        cout << "    ";
        for(int i=0; i<tr.depth(it)-rootdepth; ++i) 
            cout << "  ";
        cout << (*it) << endl << flush;
        ++it;
    }
}

class MyModelHandler: public ModelHandler
{
public:
    MyModelHandler() /*: ModelHandler()*/ { }
//    ~MyModelHandler() { }

    void on_read_model(const XmlString& formalismUrl) {
        cout << "read model : formalism = " << formalismUrl << endl;
    }

    void on_read_model_attribute(const Attribute& attribute) {
        print_tree(attribute, attribute.begin(), attribute.end());
    }

    void on_read_node(const XmlString& id,
            const XmlString& nodeType,
            const AttributeMap& attributes,
            const XmlStringList& references) {
        cout << "read node : " << id << ", " << nodeType << endl;
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
            print_tree(it->second, it->second.begin(), it->second.end());
        }
        for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }
    }

    void on_read_arc(const XmlString& id,
            const XmlString& arcType,
            const XmlString& source,
            const XmlString& target,
            const AttributeMap& attributes,
            const XmlStringList& references) {
        cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
            print_tree(it->second, it->second.begin(), it->second.end());
        }
        for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }
    }
};


int main(int argc, char* argv[])
{
    string filepath;
    if(argc < 2 )
    {
        cerr << "Need at least 1 argument" << endl;
        return 1;
    }

    filepath = argv[1];

    ModelHandlerPtr handlerPtr(new MyModelHandler);
    ExpatModelParser parser = ExpatModelParser(handlerPtr);
    parser.parse_file(filepath);

    return 0;
}

