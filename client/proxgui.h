//-----------------------------------------------------------------------------
// Copyright (C) 2009 Michael Gernoth <michael at gernoth.net>
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// GUI functions
//-----------------------------------------------------------------------------
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void ShowGraphWindow(void);
void HideGraphWindow(void);
void RepaintGraphWindow(void);
void MainGraphics(void);
void InitGraphics(int argc, char **argv);
void ExitGraphics(void);

#define MAX_GRAPH_TRACE_LEN (40000 * 8 )
extern int GraphBuffer[MAX_GRAPH_TRACE_LEN];
extern int GraphTraceLen;
extern int s_Buff[MAX_GRAPH_TRACE_LEN];

extern double CursorScaleFactor;
extern int PlotGridX, PlotGridY, PlotGridXdefault, PlotGridYdefault;
extern int CommandFinished;
extern int offline;

//Operations defined in data_operations
extern int autoCorr(const int* in, int *out, size_t len, int window);
extern int directionalThreshold(const int* in, int *out, size_t len, int8_t up, int8_t down);


#ifdef __cplusplus
}
#endif
