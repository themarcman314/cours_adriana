int main(void) {
	int totalScore = 45;
	int totalTests = 10;

	// ❌ WITHOUT CAST: 45 / 10 evaluates to 4, then becomes 4.0
	double average1 = totalScore / totalTests; // Result: 4.0

	// ✅ WITH CAST: Converts totalScore to 45.0 first, forcing float
	// division
	double average2 = (double)totalScore / totalTests; // Result: 4.5
}
