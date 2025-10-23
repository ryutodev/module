int tab;
void features(int tab) {
ImGui::PushFont(my_font);
    if (tab == 0) {
  ImGui::Checkbox(_("Enable Esp"),&esp_enable);
  ImGui::Checkbox(_("Esp Box"),&esp_bools::draw_box);
  ImGui::SameLine();
  ImGui::ColorEdit3(_(""), (float *) &BoxColor,ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoBorder);
  ImGui::SliderInt(_("Corned Box"), &cornedbox,0,10);
  ImGui::Checkbox(_("Esp Line"),&esp_bools::draw_line);
  ImGui::Checkbox(_("Esp Out Of Screen"), &outoffov);
  ImGui::Checkbox(_("Visible indicator"), &oofvis);
  ImGui::Checkbox(_("Esp Distance"), &esp_bools::esp_distance);
}
    if (tab == 1) {
	
    }
    if (tab == 2) {
		
	}
    if (tab == 3) {
		
	}
    if (tab == 4) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1,1));
        ImGui::ColorEdit3("Accent color", (float*)&accentCol, ImGuiColorEditFlags_NoInputs);
		ImGui::PopStyleColor();
        auto& Style = ImGui::GetStyle();
        Style.Colors[ImGuiCol_CheckMark] = accentCol;
        Style.Colors[ImGuiCol_SliderGrab] = accentCol;
        Style.Colors[ImGuiCol_SliderGrabActive] = accentCol;
    }
	
}

