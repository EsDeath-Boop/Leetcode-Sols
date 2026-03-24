class Solution {
 public:
  long long maxScore(vector<int>& points, int m) {
    long l = 0;
    long r = (m + 1L) / 2 * points[0] + 1;

    while (l < r) {
      const long mid = (l + r + 1) / 2;
      if (isPossible(points, mid, m))
        l = mid;
      else
        r = mid - 1;
    }

    return l;
  }

 private:
  bool isPossible(const vector<int>& points, long minVal, long m) {
    long moves = 0;
    long prevMoves = 0;
    for (int i = 0; i < points.size(); ++i) {
      const long required =
          max(0L, (minVal + points[i] - 1) / points[i] - prevMoves);
      if (required > 0) {
        moves += 2L * required - 1;
        prevMoves = required - 1;
      } else if (i + 1 < points.size()) {
        moves += 1;
        prevMoves = 0;
      }
      if (moves > m)
        return false;
    }
    return true;
  }
};