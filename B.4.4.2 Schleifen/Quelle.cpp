
int main() {
	int i, k, n;

	i = 101, k = 5, n = 10;
	while (i > 0) k = 2 * k; // ...

	i = 101, k = 5, n = 10;
	while (i != 0) i = i - 2; // ...

	i = 101, k = 5, n = 10;
	while (n != i) { // ...
		++i;
		n = 2 * i;
	}
}