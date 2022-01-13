class Solution {
public:
    double _myPow(double x, long long int n) {
		if (n == 1)
			return x;
		if (n % 2 == 0) {
			return _myPow(x*x, n/2);
		}
		else {
			return _myPow(x*x, (n-1)/2) * x;
		}
	}

    double myPow(double x, int n) {
		if (n == 0)
			return 1;
		long long int N = n;
		if (N < 0)
			return 1.0 / _myPow(x, -1 * N);
		return _myPow(x, N);
	}
};
