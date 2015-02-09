#include <data_operations.h>

extern void PrintAndLog(char *fmt, ...);

int autoCorr(const int* in, int *out, size_t len, int window)
{
	static int CorrelBuffer[MAX_GRAPH_TRACE_LEN];

	if (window == 0) {
		PrintAndLog("needs a window");
		return 0;
	}
	if (window >= len) {
		PrintAndLog("window must be smaller than trace (%d samples)",
		len);
		return 0;
	}

	PrintAndLog("performing %d correlations", len - window);

	for (int i = 0; i < len - window; ++i) {
		int sum = 0;
		for (int j = 0; j < window; ++j) {
			sum += (in[j]*in[i + j]) / 256;
		}
		CorrelBuffer[i] = sum;
	}
	//GraphTraceLen = GraphTraceLen - window;
	memcpy(out, CorrelBuffer, len * sizeof (int));
	return 0;
}
int directionalThreshold(const int* in, int *out, size_t len, int8_t up, int8_t down)
{
	int lastValue = in[0];
	out[0] = 0; // Will be changed at the end, but init 0 as we adjust to last samples value if no threshold kicks in.

	for (int i = 1; i < len; ++i) {
		// Apply first threshold to samples heading up
		if (in[i] >= up && in[i] > lastValue)
		{
			lastValue = out[i]; // Buffer last value as we overwrite it.
			out[i] = 1;
		}
		// Apply second threshold to samples heading down
		else if (in[i] <= down && in[i] < lastValue)
		{
			lastValue = out[i]; // Buffer last value as we overwrite it.
			out[i] = -1;
		}
		else
		{
			lastValue = out[i]; // Buffer last value as we overwrite it.
			out[i] = out[i-1];
		}
	}
	out[0] = out[1]; // Align with first edited sample.
	return 0;
}
