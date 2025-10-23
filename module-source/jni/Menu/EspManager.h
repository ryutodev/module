void* myplayer;
namespace ESP {
  void DrawEsp(){
  if(esp_enable){
  players.clear();
  static auto getsceneobject = (csharparray*(*)(void *xyi,int ppaaaad))(getAbsoluteAddress("libil2cpp.so", 0x2A7D648));
  static auto gettypebyname = (void*(*)(int gavn,bool djks,bool lssl))(getAbsoluteAddress("libil2cpp.so", 0x1ACA14C));
  auto getstr = (int(*)(char*))(dlsym(dlopen("libil2cpp.so",1),"il2cpp_string_new"));
  auto testesse=getsceneobject(gettypebyname(getstr("Photon.MonoBehaviour, Assembly-CSharp"),false,false),1);
  for (int i = 0; i < testesse->size; i++) {
  Object* object228 = (Object*)testesse->ptr[i];
  players.push_back(object228); 
}   
  for(int i=0;i<players.size();i++){
  static auto get_tr = (void *(*)(void *))(getAbsoluteAddress("libil2cpp.so",0x3183D5C));
  static auto get_pos = (Vector3(*)(void *))(getAbsoluteAddress("libil2cpp.so",0x3196F8C));
  static auto get_cam = (void*(*)())(getAbsoluteAddress("libil2cpp.so",0x2A75248));
  static auto worldtoscreen =(Vector3(*)(void*,Vector3))(getAbsoluteAddress("libil2cpp.so",0x2A74984));
  static auto get_forward =(Vector3(*)(void*))(getAbsoluteAddress("libil2cpp.so",0x3197BE4));
  static auto getalive = (bool(*)(void*))(getAbsoluteAddress("libil2cpp.so",0x2A7C5F4));
  static auto get_nickname = (monoString*(*)(void*))(getAbsoluteAddress("libil2cpp.so",0x2AB9CD0));
  static auto get_health = (int(*)(void*))(getAbsoluteAddress("libil2cpp.so",0x126028C)); 
  void* Player = players[i];
  if(!getalive(Player))continue;
  void* camera = get_cam();
  Vector3 HeadPos= get_pos(get_tr(Player))+Vector3(0,1.9f,0);
  Vector3 HeadPos2= get_pos(get_tr(Player))+Vector3(0,0,0);
  Vector3 Toepos= get_pos(get_tr(Player));
  Vector3 Toeposi= worldtoscreen(camera, Vector3(Toepos.x,Toepos.y,Toepos.z));
  Vector3 HeadPosition = worldtoscreen(camera, Vector3(HeadPos.x,HeadPos.y,HeadPos.z));
  Vector3 HeadPosition2 = worldtoscreen(camera, Vector3(HeadPos2.x,HeadPos2.y,HeadPos2.z));
  Vector3 viewpos = get_pos(get_tr(get_cam()));
  auto posit = get_pos(get_tr(Player));
  auto distance = Vector3::Distance(viewpos, posit);
  auto ray = visiblechecker[Player];
  auto checker = false;
  int Hight = HeadPosition.y - Toeposi.y;
  int Width = Hight *0.6;
  auto w2sC = world2screen_c(posit + Vector3(0, 0.9, 0), checker);
  if (HeadPosition.z >1.0f) {
                        if (outoffov && (ray || !visible)) {
                            if ((w2sC.x < 0 || w2sC.x > glWidth) ||
                                (w2sC.y < 0 || w2sC.y > glHeight) || !checker) {
                                constexpr int maxpixels = 200;

                                int pixels = maxpixels;

                                if (checker) {
                                    if (w2sC.x < 0)
                                        pixels = std::clamp((int) -w2sC.x, 0,
                                                            maxpixels);
                                    if (w2sC.y < 0)
                                        pixels = std::clamp((int) -w2sC.y, 0,
                                                            maxpixels);

                                    if (w2sC.x > glWidth)
                                        pixels = std::clamp((int) w2sC.x - glWidth, 0,
                                                            maxpixels);
                                    if (w2sC.y > glHeight)
                                        pixels = std::clamp((int) w2sC.y - glHeight, 0,
                                                            maxpixels);
                                }

                                float opacity = (float) pixels / (float) maxpixels;

                                float size = 5.0f;
                                Vector3 viewdir = get_forward(
                                        get_tr(get_cam()));
                                Vector3 targetdir = (posit - viewpos).normalized();

                                float viewangle = atan2(viewdir.z, viewdir.x) * Rad2Deg;
                                float targetangle =
                                        atan2(targetdir.z, targetdir.x) * Rad2Deg;

                                if (viewangle < 0) viewangle += 360;
                                if (targetangle < 0) targetangle += 360;

                                float angle = targetangle - viewangle;


                                while (angle < 0) angle += 360;
                                while (angle > 360) angle -= 360;

                                angle = 360 - angle;
                                angle -= 90;

                                //LOGI("v '%.2f', t '%.2f', a '%.2f'", viewangle, targetangle, angle);


                                arc(glWidth / 2, glHeight / 2, 226 + distance * 2,
                                    angle - size,
                                    angle + size,
                                    ImColor(1.f, 1.f, 1.f, 1.f * opacity), 4.f);

                                if (oofvis) {
                                    arc(glWidth / 2, glHeight / 2,
                                        220 + distance * 2, angle - size,
                                        angle + size,
                                        ray ? ImColor(0.1f, 1.0f, 0.1f, 0.5f * opacity)
                                            : ImColor(1.0f, 0.1f, 0.1f, 0.5f * opacity),
                                        1.5f);
                                }
                            }
                        }
						if(esp_distance){
						  Vector3 MyPosi222 = get_pos(get_tr(get_cam()));
                          int DistanceTo = get_3D_Distance(MyPosi222.x, MyPosi222.y, MyPosi222.z,HeadPos.x, HeadPos.y, HeadPos.z);

                          char extra[10];
						  auto textsize1 = 10; 
                          sprintf(extra, " %0.0fm", DistanceTo);
						}
  if(draw_box){
  ImGui::GetBackgroundDrawList()->AddRect(ImVec2(HeadPosition.x-Width/2,glHeight-HeadPosition.y), ImVec2(HeadPosition.x+Width/2,glHeight-HeadPosition.y+Hight), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0,1)),cornedbox,0,4);
  ImGui::GetBackgroundDrawList()->AddRect(ImVec2(HeadPosition.x-Width/2,glHeight-HeadPosition.y), ImVec2(HeadPosition.x+Width/2,glHeight-HeadPosition.y+Hight), ImGui::ColorConvertFloat4ToU32(ImVec4(BoxColor)),cornedbox,0,2);
  }
  if(draw_line){
  ImGui::GetBackgroundDrawList()->AddLine(ImVec2(glWidth/2,glHeight), ImVec2(HeadPosition.x,glHeight- HeadPosition.y), ImGui::ColorConvertFloat4ToU32(ImVec4(1,0,0,1)),1);
  }
 }
  }
  }
}
}