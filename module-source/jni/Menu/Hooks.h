/*
inline void arc(float x, float y, float radius, float min_angle, float max_angle, ImColor col, float thickness) {
    ImGui::GetBackgroundDrawList()->PathArcTo(ImVec2 (x, y), radius, Deg2Rad * min_angle, Deg2Rad * max_angle, 32);
    ImGui::GetBackgroundDrawList()->PathStroke(col, false, thickness);
}
static void *get_photon(void *player) {
return *(void **)((uint64_t) player + 0xAC);	   	 
}
ImVec2 world2screen_c(Vector3 pos, bool &checker, bool fixpos = false) {
	static auto cam = (void*(*)())(getAbsoluteAddress("libil2cpp.so",0x2A75248));
	auto camera = cam();
	static auto WorldToScreenPoint =(Vector3(*)(void*,Vector3))(getAbsoluteAddress("libil2cpp.so",0x2A74984));
    if (!camera) return {0,0};
    Vector3 worldPoint = WorldToScreenPoint(camera,pos);       checker = worldPoint.z > 0.1f;
    return {worldPoint.x, glHeight - worldPoint.y};
}
void DrawLineGlow(ImVec2 start,ImVec2 end,ImVec4 col,float size, int gsize) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(col),size);
        for(int i = 0; i < gsize; i++) {
            ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(ImVec4(col.x,col.y,col.z,col.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize))),size + i);
        }
    }
*/
