#pragma exceptions off

#include "render_manager_error.h"

RenderManagerError::RenderManagerError(void *dev) {
    device = dev;
    error_code = 0;
}

int RenderManagerError::format_error(int res_id, int arg) {
    return func_2265E0(device, 0x400, res_id, arg);
}

RenderManagerError::~RenderManagerError() {
}

void RenderManagerError::translate_error(int hr) {
    if (hr == 0) return;
    error_code = hr;
    if (hr == (int)0x88770118) { format_error(0x17B7, 0); return; }
    if (hr == (int)0x80004001) return;
    if (hr == (int)0x8877041A) return;
    if (hr == (int)0x88770140) { format_error(0x17B7, 0); return; }
    if (hr == (int)0x887700FA) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x887700F0) { format_error(0x17C2, 0); return; }
    if (hr == (int)0x887707EE) return;
    if (hr == (int)0x88770136) { format_error(0x17B1, 0); return; }
    if (hr == (int)0x887700E6) return;
    if (hr == (int)0x8877012C) return;
    if (hr == (int)0x8007000E) return;
    if (hr == (int)0x8877042E) return;
    if (hr == (int)0x887700DC) return;
    if (hr == (int)0x88770410) return;
    if (hr == (int)0x887700D2) return;
    if (hr == (int)0x8877014A) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x887700C8) return;
    if (hr == (int)0x887700BE) return;
    if (hr == (int)0x80004002) { format_error(0x17B5, 0); return; }
    if (hr == (int)0x887700AA) return;
    if (hr == (int)0x887700A0) return;
    if (hr == (int)0x88770820) return;
    if (hr == (int)0x88770154) return;
    if (hr == (int)0x88770096) return;
    if (hr == (int)0x80070057) return;
    if (hr == (int)0x88770082) return;
    if (hr == (int)0x8877009B) return;
    if (hr == (int)0x88770078) return;
    if (hr == (int)0x80004005) { format_error(0x17B5, 0); return; }
    if (hr == (int)0x8877005A) return;
    if (hr == (int)0x887707E4) return;
    if (hr == (int)0x8877015E) return;
    if (hr == (int)0x88770050) return;
    if (hr == (int)0x887707DA) return;
    if (hr == (int)0x887707F8) return;
    if (hr == (int)0x8877080C) return;
    if (hr == (int)0x88770046) return;
    if (hr == (int)0x887703F2) return;
    if (hr == (int)0x8877003C) return;
    if (hr == (int)0x88770032) return;
    if (hr == (int)0x88770028) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x88770122) return;
    if (hr == (int)0x8877001E) return;
    if (hr == (int)0x887703E8) return;
    if (hr == (int)0x8877010E) return;
    if (hr == (int)0x887707D0) return;
    if (hr == (int)0x887703FC) return;
    if (hr == (int)0x88770005) return;
    if (hr == (int)0x88770014) return;
    if (hr == (int)0x8877000A) { format_error(0x17B7, 0); return; }
}
