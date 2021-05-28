double maxi(double x, double y) {
      if (x>y) return x; else return y;
}
// Function to determine maximum of two numbers needs to specify type
// ... unless you use function templates:
// 5
// z
// 5e-07
// Output:
template<class T>
T maxi(T x, T y) {
   if (x>y) return x; else return y;
}
