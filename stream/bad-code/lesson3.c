#define MAX(a, b) a > b
#define MIN(a, b) a < b
#define STR(s1, s2) s1 < s2
#define COMBINE(a, b) MIN(a, b) == MAX(a,b)

int main() {
  const char max = MAX(10, 20);
  const char min = MIN(10, 20);
  const char str = STR("hello", "world");
  const char combine = COMBINE(max, min);
}
