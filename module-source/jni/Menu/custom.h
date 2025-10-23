#define HOOKAF(retttt, func, ...) \
    retttt (*orig##func)(__VA_ARGS__); \
    retttt my##func(__VA_ARGS__)

HOOKAF(void, Input, void *thiz, void *ex_ab, void *ex_ac) {
    origInput(thiz, ex_ab, ex_ac);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz);
    return;
}
void DrawFilledCircleGlow(ImVec2 start, float radius, ImVec4 col, int segments, int gsize) {
    for (int i = 0; i < gsize; i++) {
        ImGui::GetWindowDrawList()->AddCircleFilled(start, radius + i, ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), segments);
    }
}

void DrawMainText(ImVec2 CurrentWindowPos, const char* text) {
    ImGui::GetWindowDrawList()->AddText(ImVec2(185 * scale + CurrentWindowPos.x, 17 * scale + CurrentWindowPos.y), ImColor(255, 255, 255), text);
}
