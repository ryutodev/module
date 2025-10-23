#include <thread>
#include <pthread.h>
#include <jni.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "Rect.h"
#include "Includes/Obfuscate.h"
#include "Includes/Utils.h"
#include "Includes/Logger.h"
#include "KittyMemory/MemoryPatch.h"
#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>
#include "Unity/Vector2.H"
#include "Unity/Vector3.h"
#include "Unity/Vector4.h"
#include "Unity/Rect.H"
#include "Unity/Color.H"
#include "Unity/Quaternion.H"
#include "includes/Dobby/dobby.h"
// we will run our hacks in a new thread so our while loop doesn't block process main thread
#define targetLibName OBFUSCATE("libil2cpp.so")
#include "Includes/Macros.h"
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_opengl3.h"
#include "../ImGui/imgui_internal.h"
uintptr_t address = 0;
int glWidth, glHeight;
JavaVM* publicVM;
JNIEnv* publicEnv;
#include "ImGui/backends/imgui_impl_android.h"
#include "ImGui/box_shadow.cpp"
#include "Includes/charObfuscate.h"
#include "Verdana.h"
#include "ByNameModding/BNM.hpp"
using namespace BNM;
using namespace BNM::IL2CPP;
using namespace BNM::MONO_STRUCTS;
using namespace std;
#include "Menu/Fonts.h"
#include "Menu/Bools.h"
#include "Menu/EspManager.h"
#include "Menu/custom.h"
#include "Menu/LoadOffset.h"
#include "Menu/Hooks.h"
#include "Menu/Offsets.h"

#include "PixelFont.h"
#include "Font.h"

#include "zygisk.hpp"

using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

//== это вызов хука 
void hack();
//====

class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
  }

  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
        "com.SKITLSE.StandRise"
    };
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }

  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
      std::thread{hack}.detach();
    }
  }

 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};

int tab;

ImFont* verdana;
ImFont* pixel;
ImFont* smallpixel;
ImFont* tabs;
ImFont* fivepixel;

void initpurple()
{

  auto& style = ImGui::GetStyle();

    style.WindowMinSize = ImVec2(0,0);
    style.ScrollbarSize = 14.0f;
    style.ButtonTextAlign = ImVec2(0.5, 0.5);
    style.WindowTitleAlign = ImVec2(0.5, 0.5);
    style.WindowBorderSize = 3.5f;
    style.WindowRounding = 6.0f;
    style.FrameRounding = 3.0f;
    style.ScrollbarRounding = 4.0f;
}

void SetupImgui() {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    io.DisplaySize = ImVec2((float) glWidth, (float) glHeight);

    // Setup Dear ImGui style
    // Setup Platform/Renderer backends
    ImGui_ImplOpenGL3_Init("#version 300 es");

    // init styles
    ImGuiStyle &style = ImGui::GetStyle();
    ImVec4 *colors = style.Colors;

    colors[ImGuiCol_WindowBg] = ImColor(18, 18, 18);
    auto &Style = ImGui::GetStyle();


    Style.Colors[ImGuiCol_FrameBg] = ImVec4(0.157f, 0.157f, 0.157f, 0.541f);
    Style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.157f, 0.157f, 0.157f, 0.400f);
    Style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.235f, 0.235f, 0.235f, 0.671f);
    Style.Colors[ImGuiCol_Button] = ImVec4(0.157f, 0.157f, 0.157f, 0.400f);
    Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
    Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
    Style.Colors[ImGuiCol_Header] = ImVec4(0.157f, 0.157f, 0.157f, 0.310f);
    Style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.157f, 0.157f, 0.157f, 0.800f);
    Style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
    Style.Colors[ImGuiCol_Separator] = ImVec4(0.470f, 0.470f, 0.470f, 0.500f);
    Style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.343f, 0.343f, 0.343f, 0.780f);
    Style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.320f, 0.320f, 0.320f, 1.000f);
    Style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.157f, 0.157f, 0.157f, 0.200f);
    Style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.157f, 0.157f, 0.157f, 0.671f);
    Style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.260f, 0.260f, 0.260f, 0.950f);
    Style.Colors[ImGuiCol_Tab] = ImVec4(0.157f, 0.157f, 0.157f, 0.863f);
    Style.Colors[ImGuiCol_TabHovered] = ImVec4(0.157f, 0.157f, 0.157f, 0.800f);
    Style.Colors[ImGuiCol_TabActive] = ImVec4(0.232f, 0.232f, 0.232f, 1.000f);
    Style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
    style.WindowRounding = 4;
    style.WindowPadding = ImVec2(0, 0);
    // ImGui::StyleColorsLight();
    //Menu::initStyle();
    initpurple();

    // We load the default font with increased size to improve readability on many devices with "high" DPI.
    ImFontConfig font_cfg;
    
    io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 22.0f, &font_cfg);

    
	ImFontConfig font_cfg2;
	ImFontConfig font_cfg3;
    io.Fonts->AddFontDefault(&font_cfg);
	my_font = io.Fonts->AddFontFromMemoryTTF(&Verdana, sizeof Verdana, 21.05f*scale, &font_cfg);
	
	
    dpiscale = 1.1f;
    
    // Arbitrary scale-up
    ImGui::GetStyle().ScaleAllSizes(3.5f*dpiscale);
}



EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (!setup) {
        SetupImgui();
        setup = true;
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
    
    
    ImGui::SetNextWindowSize(ImVec2(1000,629),ImGuiCond_FirstUseEver);
    if(ImGui::Begin(OBFUSCATE("Tenmium"),0, ImGuiWindowFlags_NoResize)) {
        if (ImGui::Button("Aim")) {
            tab = 1;
        }
        ImGui::SameLine();
        if (ImGui::Button("Esp")) {
            tab = 2;
        }
        if (tab == 1) {           
        }
        if (tab == 2) {
  ImGui::Checkbox("Enable Esp",&esp_enable);
  ImGui::Checkbox("Esp Box",&draw_box);
  ImGui::SameLine();
  ImGui::ColorEdit3("", (float *) &BoxColor,ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoBorder);
  ImGui::SliderInt("Corned Box", &cornedbox,0,10);
  ImGui::Checkbox("Esp Line", &draw_line);
  ImGui::Checkbox("Esp Out Of Screen", &outoffov);
  ImGui::Checkbox("Visible indicator", &oofvis);
  ImGui::Checkbox("Esp Distance", &esp_distance);
        }
    }
  ImGui::End();
    //render
	ESP::DrawEsp();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return old_eglSwapBuffers(dpy, surface);
}


void *mod() {
system(OBFUSCATE("echo 0 > /proc/sys/kernel/randomize_va_space"));
    do {
        usleep(600);
    } while (!isLibraryLoaded("libil2cpp.so"));
	auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
	DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
}


void *imgui_go(void *) {
    address = findLibrary("libil2cpp.so");
    auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
    std::thread(mod).detach();
    return 0;
}

//__attribute__((constructor))
void hack() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
	    void *sym_input = DobbySymbolResolver(("/system/lib/libinput.so"), ("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
    if (NULL != sym_input) {
        DobbyHook((void *)sym_input, (void *) myInput, (void **)&origInput);
    }
        pthread_t ptid;
    pthread_create(&ptid, NULL, imgui_go, NULL);
    
}



REGISTER_ZYGISK_MODULE(MyModule)
