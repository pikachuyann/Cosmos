SpnCppFile << "#include \"marking.hpp\"\n";
SpnCppFile << "\n";
SpnCppFile << "const int NbPlaces = 1;\n";
SpnCppFile << "\n";
SpnCppFile << "class abstractMarkingImpl {\n";
SpnCppFile << "public:\n";
SpnCppFile << "	int place1;\n";
SpnCppFile << "	\n";
SpnCppFile << "	int LHALocation;\n";
SpnCppFile << "};\n";
SpnCppFile << "\n";
SpnCppFile << "void abstractMarking::resetToInitMarking(){\n";
SpnCppFile << "	P->LHALocation=0;\n";
SpnCppFile << "	\n";
SpnCppFile << "	P->place1=0;\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "\n";
SpnCppFile << "abstractMarking::abstractMarking() {\n";
SpnCppFile << "	P= new abstractMarkingImpl;\n";
SpnCppFile << "	resetToInitMarking();\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "abstractMarking::abstractMarking(const std::vector<int>& m) {\n";
SpnCppFile << "	P = new abstractMarkingImpl;\n";
SpnCppFile << "	setVector(m);\n";
SpnCppFile << "}\n";
SpnCppFile << "abstractMarking::abstractMarking(const abstractMarking& m) {\n";
SpnCppFile << "	P= new abstractMarkingImpl;\n";
SpnCppFile << "	\n";
SpnCppFile << "	*this = m;\n";
SpnCppFile << "	\n";
SpnCppFile << "};\n";
SpnCppFile << "\n";
SpnCppFile << "\n";
SpnCppFile << "abstractMarking& abstractMarking::operator = (const abstractMarking& m) {\n";
SpnCppFile << "	*P = *(m.P);\n";
SpnCppFile << "	return *this;\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "abstractMarking::~abstractMarking() {\n";
SpnCppFile << "	delete(P);\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "void abstractMarking::setLocation(int l){\n";
SpnCppFile << "	P->LHALocation = l;\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "\n";
SpnCppFile << "int abstractMarking::retriveLocation()const{\n";
SpnCppFile << "	return P->LHALocation;\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "void abstractMarking::print()const{\n";
SpnCppFile << "	std::cerr << \"Marking:\"<< std::endl;\n";
SpnCppFile << "\n";
SpnCppFile << "	std::cerr << \"Place1: \"<< std::endl;\n";
SpnCppFile << "\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "int abstractMarking::getNbOfTokens(int p)const {\n";
SpnCppFile << "	switch (p) {\n";
SpnCppFile << "		case 1:\n";
SpnCppFile << "			return P->place1;\n";
SpnCppFile << "	}\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "std::vector<int> abstractMarking::getVector()const {\n";
SpnCppFile << "	std::vector<int> v(NbPlaces);\n";
SpnCppFile << "	v[0] = P->place1;\n";
SpnCppFile << "	return v;\n";
SpnCppFile << "}\n";
SpnCppFile << "\n";
SpnCppFile << "void abstractMarking::setVector(const std::vector<int>&v) {\n";
SpnCppFile << "	P->place1= v[0];\n";
SpnCppFile << "};SpnCppFile << "\n";