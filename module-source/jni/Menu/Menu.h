namespace Menu {

void menu_styles()
{
    ImGui::StyleColorsDark();
    auto& Style = ImGui::GetStyle();
    Style.WindowBorderSize = 2.0f;
	Style.FrameBorderSize = 3.0f;
    Style.GrabRounding = 5.0f;
	Style.WindowRounding = 0.0f;
	Style.FrameRounding = 0.0f;
    Style.GrabMinSize = 35.0f;
    Style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0.118f, 0.118f, 0.118f, 0.100f);
    Style.Colors[ImGuiCol_FrameBgActive] = ImColor(0.118f, 0.118f, 0.118f, 0.100f);
    Style.Colors[ImGuiCol_FrameBg] = ImColor(0.118f, 0.118f, 0.118f, 0.100f);
    Style.Colors[ImGuiCol_CheckMark] = accentCol;
    Style.Colors[ImGuiCol_WindowBg] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
    Style.Colors[ImGuiCol_Border] = ImColor(0.071f, 0.071f, 0.071f, 0.71f);
    Style.Colors[ImGuiCol_Button] = ImColor(0.071f, 0.071f, 0.071f, 0.600f);
    Style.Colors[ImGuiCol_ButtonHovered] = ImColor(0.071f, 0.071f, 0.071f, 0.600f);
    Style.Colors[ImGuiCol_HeaderHovered] = ImColor(0.071f, 0.071f, 0.071f, 1.500f);
    Style.Colors[ImGuiCol_HeaderActive] = ImColor(0.071f, 0.071f, 0.071f, 1.500f);
    Style.Colors[ImGuiCol_Header] = ImColor(0.071f, 0.071f, 0.071f, 1.500f);
    Style.Colors[ImGuiCol_SliderGrab] = accentCol;
    Style.Colors[ImGuiCol_SliderGrabActive] = accentCol;
    ImGuiIO& io = ImGui::GetIO();
}
 void load_menu() {
            static int menutab = 0;
            float dpiscale = 1.0f;
            static int game = 0;
            static bool opened = true;
            int curtab = 1;
			ImGui::GetStyle().WindowMinSize = ImVec2(0, 0);
            ImGui::SetNextWindowPos(ImVec2(glWidth / 2 - 100, glHeight - 60));
            ImGui::SetNextWindowSize(ImVec2(400, 100));
            ImGui::Begin(OBFUSCATE("menu_open"), nullptr,ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
            if (ImGui::InvisibleButton(OBFUSCATE("##dbuitiin"),ImGui::GetWindowSize())) 
			open_menu = !open_menu;    	   
		    ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(glWidth / 2 - 100, glHeight - 20),ImVec2(glWidth / 2 + 100, glHeight - 10),IM_COL32(255, 255, 255, 150), 1);
		    if(!open_menu) 
            return;
    ImGui::SetNextWindowSize(ImVec2(600.000f*scale, 500.000f*scale), ImGuiCond_Once);
    ImGui::Begin("drawme", NULL, 35 | ImGuiWindowFlags_NoBackground);
	ImGui::PushFont(my_font);
	struct game_data {
                const char* name;
                std::string status;
                std::string last_updated;
                bool undetected;
            };
        ImGui::PushFont(my_font);
        static std::vector<game_data> yyyyyy = {
        {"visuals"},
        {"aimbot"},
        {"misc"},
        {"profile"},
        {"menu"}
            };
    ImVec2 P1, P2;
    ImDrawList* pDrawList;
    const auto& CurrentWindowPos = ImGui::GetWindowPos();
    const auto& pWindowDrawList = ImGui::GetWindowDrawList();
    const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
    const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();
    P1 = ImVec2(2.000f*scale, 495.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(598.000f*scale, 4.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilled(P1, P2, ImColor(0.130f, 0.116f, 0.116f, 1.000f), 0.000f);
    P1 = ImVec2(4.200f*scale, 4.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(596.000f*scale, 496.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRect(P1, P2, ImColor(0.268f, 0.259f, 0.259f, 1.000f), 0.000f);
    P1 = ImVec2(10.000f*scale, 10.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(589.000f*scale, 489.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRect(P1, P2, ImColor(0.242f, 0.219f, 0.219f, 1.000f), 0.000f);
    P1 = ImVec2(11.000f*scale, 11.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(588.000f*scale, 488.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilled(P1, P2, ImColor(0.056f, 0.056f, 0.056f, 1.000f), 0.000f);
    P1 = ImVec2(140.000f*scale, 10.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(140.000f*scale, 488.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddLine(P1, P2, ImColor(0.195f, 0.188f, 0.188f, 1.000f), 1.500f);
    P1 = ImVec2(12.000f*scale, 13.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(325.000f*scale, 12.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilledMultiColor(P1, P2,
    ImColor(0.857f, 0.000f, 1.000f, 1.000f),
    ImColor(0.000f, 1.000f, 0.494f, 1.000f),
    ImColor(0.506f, 0.000f, 0.974f, 1.000f),
    ImColor(0.000f, 1.000f, 0.909f, 1.000f));
    P1 = ImVec2(300.000f*scale, 13.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(587.000f*scale, 12.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilledMultiColor(P1, P2,
    ImColor(0.196f, 0.719f, 0.698f, 1.000f),
    ImColor(0.961f, 1.000f, 0.000f, 1.000f),
    ImColor(1.000f, 0.000f, 0.935f, 1.000f),
    ImColor(0.214f, 0.069f, 1.000f, 1.000f));
    P1 = ImVec2(160.000f*scale, 30.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(570.000f*scale, 470.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRect(P1, P2, ImColor(0.182f, 0.175f, 0.175f, 1.000f), 0.000f);
    P1 = ImVec2(162.000f*scale, 32.000f*scale);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(569.000f*scale, 469.000f*scale);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilled(P1, P2, ImColor(0.087f, 0.087f, 0.087f, 1.000f), 0.000f);
      if (menutab == 0) {
            DrawMainText(CurrentWindowPos, "visuals");
        }
        if (menutab == 1) {
            DrawMainText(CurrentWindowPos, "aimbot");
        }
        if (menutab == 2) {
            DrawMainText(CurrentWindowPos, "misc");
        }
        if (menutab == 3) {
            DrawMainText(CurrentWindowPos, "profile");
        }
        if (menutab == 4) {
            DrawMainText(CurrentWindowPos, "menu");
        }

    auto& Style = ImGui::GetStyle();
    ImGui::SetCursorPos(ImVec2(20*scale, 20*scale));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0, 0, 0, 0));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0, 0, 0, 0));
    ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0, 0, 0, 0));
    ImGui::BeginChild("djkalsllz", ImVec2(90*scale, 150*scale), false);
    {
        for (unsigned int i = 0; i < yyyyyy.size(); i++)
        {
            bool selected = (menutab == i);
            bool selected1 = (menutab == i + 1);

            if (ImGui::Selectable(yyyyyy[i].name, &selected, 0, ImVec2(130, 0)))
            {
                menutab = i;
            }

            if (selected1)
            {
                Style.Colors[ImGuiCol_Text] = ImColor(accentCol.x, accentCol.y, accentCol.z);
            }
            else
            {
                Style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
            }
        }
    }
    ImGui::EndChild();
    ImGui::PopStyleColor(3);
    ImGui::SetCursorPos(ImVec2(165*scale, 45*scale));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.239f, 0.239f, 0.239f, 0.300f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));
    ImGui::BeginChild("##ponnsa", ImVec2(400*scale, 421*scale), true);
    {
        features(menutab);
    }
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    ImGui::End();
	}
}
