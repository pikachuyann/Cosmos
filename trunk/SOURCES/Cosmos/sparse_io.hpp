
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/operation.hpp>

#include <iostream>

namespace boost { namespace numeric { namespace ublas {

    namespace io {

        template<class ME>
        class sparse_ioproxy {
        public:
            typedef ME matrix_expression_type;
            typedef sparse_ioproxy<ME> self_type;
            sparse_ioproxy(matrix_expression_type & me) : me(me) {}

            matrix_expression_type & operator() () const {
                return me;
            }
            matrix_expression_type & operator() () {
                return me;
            }

        private:
            sparse_ioproxy () {}
            matrix_expression_type  &me;
        };

        template < class ME >
        sparse_ioproxy<ME> sparse(ME& me) {
            return sparse_ioproxy<ME>(me);
        }

        template<class E, class T, class ME>
        std::basic_ostream<E, T> &
        output (std::basic_ostream<E, T> &os,
                const sparse_ioproxy<ME> m,
                row_major_tag) {

            typedef typename ME::size_type size_type;
            typedef ME ex_type;
            size_type size1 = m () .size1 ();
            size_type size2 = m () .size2 ();
            std::basic_ostringstream<E, T, std::allocator<E> > s;
            s.flags (os.flags ());
            s.imbue (os.getloc ());
            s.precision (os.precision ());
            s << '[' << size1 << ',' << size2 << "]";
            s << "(";
            typename ex_type::const_iterator1 i = m().begin1();
            typename ex_type::const_iterator1 n = m().end1();
            bool one_back = (i != n);
            for (; i != n; ++i) {
              typename ex_type::const_iterator2 ri=i.begin();
              typename ex_type::const_iterator2 rn=i.end();
              bool nonempty = (ri != rn);
              if (nonempty) {
                  s << "(" << ri.index1() << "," << ri.index2()
                    << ":" << *ri << ")";
                  ++ri;
              }
              for (; ri != rn; ++ri) {
                s << ",(" << ri.index1() << "," << ri.index2()
                  << ":" << *ri << ")";
              }
              if (nonempty) { s << ';'; }
            } 
            if (one_back) s.seekp(-1, std::ios_base::cur);
            s << ')';
            return os << s.str ().c_str ();
        }

        template<class E, class T, class ME>
        std::basic_ostream<E, T> &
        output (std::basic_ostream<E, T> &os,
                const sparse_ioproxy<ME> m,
                column_major_tag) {

            typedef typename ME::size_type size_type;
            typedef ME ex_type;
            size_type size1 = m () .size1 ();
            size_type size2 = m () .size2 ();
            std::basic_ostringstream<E, T, std::allocator<E> > s;
            s.flags (os.flags ());
            s.imbue (os.getloc ());
            s.precision (os.precision ());
            s << '[' << size1 << ',' << size2 << "]";
            s << "(";
            typename ex_type::const_iterator2 i = m().begin2();
            typename ex_type::const_iterator2 n = m().end2();
            bool one_back = (i != n);
            for (; i != n; ++i) {
              typename ex_type::const_iterator1 ri=i.begin();
              typename ex_type::const_iterator1 rn=i.end();
              bool nonempty = (ri != rn);
              if (nonempty) {
                  s << "(" << ri.index1() << "," << ri.index2()
                    << ":" << *ri << ")";
                  ++ri;
              }
              for (; ri != rn; ++ri) {
                s << ",(" << ri.index1() << "," << ri.index2()
                  << ":" << *ri << ")";
              }
              if (nonempty) { s << ';'; }
            } 
            if (one_back) s.seekp(-1, std::ios_base::cur);
            s << ')';
            return os << s.str ().c_str ();
        }

        template<class E, class T, class ME>
        std::basic_ostream<E, T> &
        operator << (std::basic_ostream<E, T> &os,
                     const sparse_ioproxy<ME> m) {
            return output(os, m, typename ME::orientation_category());
        }

        // note: the orientation of the data must match the orientation
        // of the matrix (otherwise push_back() will fail)
        template<class E, class T, class ME>
        std::basic_istream<E, T> &
        operator >> (std::basic_istream<E, T> &is,
                     sparse_ioproxy<ME> m) {

            typedef typename ME::size_type  size_type;
            typedef typename ME::value_type value_type;
            typedef ME ex_type;
            E ch;
            size_type size1, size2;
            if (is >> ch && ch != '[') {
              is.putback (ch);
              is.setstate (std::ios_base::failbit);
            } else if (is >> size1 >> ch && ch != ',') {
              is.putback (ch);
              is.setstate (std::ios_base::failbit);
            } else if (is >> size2 >> ch && ch != ']') {
              is.putback (ch);
              is.setstate (std::ios_base::failbit);
            } else if (! is.fail ()) {
              ME s(size1, size2);
              if (is >> ch && ch != '(') {
                is.putback (ch);
                is.setstate (std::ios_base::failbit);
              } else {
                while ( ! is.fail() ) {
                  is >> ch;
                  if (ch == ')') { 
                    break;
                  } else if (ch != '(') {
                    is.putback (ch);
                    is.setstate (std::ios_base::failbit);
                  } else {
                    // read triplet
                    size_type i,j;
                    value_type a;
                    is >> i >> ch;
                    if (is.fail() || ch != ',') {
                      is.putback (ch);
                      is.setstate (std::ios_base::failbit);
                    }
                    is >> j >> ch;
                    if (is.fail() || ch != ':') {
                      is.putback (ch);
                      is.setstate (std::ios_base::failbit);
                    }
                    is >> a >> ch;
                    if (is.fail() || ch != ')') {
                      is.putback (ch);
                      is.setstate (std::ios_base::failbit);
                    }
                    s.push_back(i,j,a);
                    is >> ch;
                    if ( ch == ')' ) {
                      break;
                    } else if ( ch != ',' && ch != ';' ) {
                      is.putback (ch);
                      is.setstate (std::ios_base::failbit);
                    }
                  }
                }
              }
              if (! is.fail ())
                m().assign_temporary (s);
            }
            return is;
        }
    }

}}}


/*int main(int argc, char *argv[])
{
  using namespace boost::numeric::ublas;
  using std::cin;
  using std::cout;
  using std::endl;

  const size_t size = 5;
  const size_t i_index[5] = { 0, 0, 1, 2, 4 };
  const size_t j_index[5] = { 0, 2, 0, 4, 4 };

  {
    compressed_matrix<double, row_major> RM(size,size);
    for (size_t i=0; i<size; ++i) RM.insert_element(i_index[i], j_index[i], 1.0);

    compressed_matrix<double, column_major> CM(size,size);
    for (size_t i=0; i<size; ++i) CM.insert_element(i_index[i], j_index[i], 1.0);

    cout << io::sparse(RM) << endl;
    cout << io::sparse(CM) << endl;
  }

  {
    compressed_matrix<double, row_major> RM;
    cin >> io::sparse(RM);
    cout << RM << endl;

    compressed_matrix<double, column_major> CM;
    cin >> io::sparse(CM);
    cout << CM << endl;
  }

  return EXIT_SUCCESS;
}*/

/* Examples:

$ echo '[1,1]((0,0:2))[2,2]((1,0:1),(2,0:1))' | ./sparse_io
[5,5]((0,0:1),(0,2:1);(1,0:1);(2,4:1);(4,4:1))
[5,5]((0,0:1),(1,0:1);(0,2:1);(2,4:1),(4,4:1))
[1,1]((2))
[2,2]((0,0),(1,0))
$ echo '' | ./sparse_io | ./sparse_io
[5,5]((0,0:1),(0,2:1);(1,0:1);(2,4:1);(4,4:1))
[5,5]((0,0:1),(1,0:1);(0,2:1);(2,4:1),(4,4:1))
[5,5]((1,0,1,0,0),(1,0,0,0,0),(0,0,0,0,1),(0,0,0,0,0),(0,0,0,0,1))
[5,5]((1,0,1,0,0),(1,0,0,0,0),(0,0,0,0,1),(0,0,0,0,0),(0,0,0,0,1))
$ echo '[1,1]((0,0:2))[2,2]((1,1:1),(2,0:1))' | ./sparse_io
[5,5]((0,0:1),(0,2:1);(1,0:1);(2,4:1);(4,4:1))
[5,5]((0,0:1),(1,0:1);(0,2:1);(2,4:1),(4,4:1))
[1,1]((2))
Check failed in file /home/a11aguwi/include/boost/numeric/ublas/matrix_sparse.hpp at line 3081:
(filled1_ == element1 + 2 && (filled2_ == zero_based (index1_data_ [filled1_ - 2]) || index2_data_ [filled2_ - 1] < k_based (element2)))
terminate called after throwing an instance of 'boost::numeric::ublas::external_logic'
  what():  external logic
Abgebrochen
  ( data was row major, but container was column major )

 */
