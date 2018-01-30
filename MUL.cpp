// can use Karatsuba or 'FFT based multiplication of polynomials' to multiply integers
// Used <https://github.com/vpetrigo/multiplication> implementation of Karatsuba
// ab = 10^n/2 a + b; cd = 10^n/2 c + d;
// ab*cd = 10^n ac + 10^n/2 (ad + bc) + bd
// ad+bc = (a+b)(c+d) - ac - bd
// hence faster than O(n^2)
// <https://apps.topcoder.com/forums/?module=Thread&threadID=568534&start=0&mc=9#770315>
// <https://apps.topcoder.com/forums/?module=Thread&threadID=618596&mc=17&view=threaded>
// <https://apps.topcoder.com/forums/;jsessionid=C78FCDDB24D62628A32D9C7389142E71?module=Thread&threadID=680738&start=0&mc=7#1262495>

// <http://numbers.computation.free.fr/Constants/Algorithms/fft.html>
// <https://www.cs.cmu.edu/afs/cs/academic/class/15451-s10/www/lectures/lect0423.txt>
// <https://math.stackexchange.com/questions/764727/concrete-fft-polynomial-multiplication-example>
// <https://gist.github.com/ir5/854921> - FFT based implementation

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

namespace Mul_lib {
    // current base functions use for operate with long integers
    constexpr int base = 1e7;
    // lenght of the long number for which naive multiplication
    // will be called in the Karatsuba function
    constexpr unsigned int len_f_naive = 32;
    // One digit size for numbers with bases multiple of ten
    constexpr int dig_size = 10;
    // How much zeroes have to be in the number
    constexpr int add_zero = base / dig_size;

    vector<long long> naive_mul(const vector<long long>& x, const vector<long long>& y) {
        auto len = x.size();
        vector<long long> res(2 * len);
        
        for (auto i = 0; i < len; ++i) {
            for (auto j = 0; j < len; ++j) {
                res[i + j] += x[i] * y[j];
            }
        }
        
        return res;
    }

    vector<long long> karatsuba_mul(const vector<long long>& x, const vector<long long>& y) {
        auto len = x.size();    
        vector<long long> res(2 * len);
        
        if (len <= len_f_naive) {
            return naive_mul(x, y);
        }
        
        auto k = len / 2;
        
        vector<long long> Xr {x.begin(), x.begin() + k};
        vector<long long> Xl {x.begin() + k, x.end()};
        vector<long long> Yr {y.begin(), y.begin() + k};
        vector<long long> Yl {y.begin() + k, y.end()};
        
        vector<long long> P1 = karatsuba_mul(Xl, Yl);
        vector<long long> P2 = karatsuba_mul(Xr, Yr);    
            
        vector<long long> Xlr(k);
        vector<long long> Ylr(k);
        
        for (auto i = 0; i < k; ++i) {
            Xlr[i] = Xl[i] + Xr[i];
            Ylr[i] = Yl[i] + Yr[i];
        }
        
        vector<long long> P3 = karatsuba_mul(Xlr, Ylr);
        
        for (auto i = 0; i < len; ++i) {
            P3[i] -= P2[i] + P1[i];
        }
        
        for (auto i = 0; i < len; ++i) {
            res[i] = P2[i];
        }

        for (auto i = len; i < 2 * len; ++i) {
            res[i] = P1[i - len];
        }

        for (auto i = k; i < len + k; ++i) {
            res[i] += P3[i - k];
        }
        
        return res;
    }

    vector<long long> get_number(istream& is) {
        string snum;
        vector<long long> vnum;
        unsigned int dig = 1;
        int n = 0;
        
        is >> snum;

        for (auto it = snum.crbegin(); it != snum.crend(); ++it) {
            n += (*it - '0') * dig;
            dig *= dig_size;
            
            if (dig == base) {
                vnum.push_back(n);
                n = 0;
                dig = 1;
            }
        }
        
        if (n != 0) {
            vnum.push_back(n);
        }
        
        return vnum;
    }

    void extend_vec(vector<long long>& v, size_t len) {    
        while (len & (len - 1)) {
            ++len;
        }
        
        v.resize(len);
    }

    void finalize(vector<long long>& res) {
        for (auto i = 0; i < res.size(); ++i) {
            res[i + 1] += res[i] / base;
            res[i] %= base;
        }
    }

    void print_res(const vector<long long>& v, ostream& os) {
        auto it = v.crbegin();
        
        string temp = "";
        // Passing leading zeroes
        while (!*it) {
            ++it;
        }
        
        while (it != v.crend()) {
            int z = -1;
            auto num = *it;
            
            if (num == 0) {
                num += 1;
            }
            
            if (num < add_zero) {
                z = 1;         
                
                while ((num *= dig_size) < add_zero) {
                    ++z;
                }
            }
            
            if (z > 0) {
                while (z--) {
                    temp += '0';
                }
            }
            temp += to_string(*it++);
        }
        int count = 0;
        while(temp[count++] == '0');
        temp.erase(0, count-1);
        os << temp << endl;
    }

    void print_vec(const vector<long long>& v) {
        size_t pos = 0;
        for (auto& i : v) {
            cout << "v[" << pos++ << "]: " << i << endl;
        }
    }
}

using namespace Mul_lib;

int main() {
    int n; scanf("%d", &n);
    while(n--){
	    vector<long long> first, second;
	    vector<long long> res;
	    
	    first = get_number(cin);
	    second = get_number(cin);
	    
	    if(first.size() == 0 or second.size() == 0){
	    	cout<<'0'<<endl;
	    	continue;
	    }

	    auto n = max(first.size(), second.size());
	    
	    extend_vec(first, n);
	    extend_vec(second, n);
	    
	    res = karatsuba_mul(first, second);
	    finalize(res);
	    
	    print_res(res, cout);
    }
    return 0;
}
