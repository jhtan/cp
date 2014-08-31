int bpow(int a, int b) {
  int res = 1;
  int y = a;
  while(b > 1) {
    if ((b & 1) == 1) {
      res *= y;
    }
    b >>= 1;
    y *= y;
    cout << "xD" <<  endl;
  }
  res *= y;
  return res;
}