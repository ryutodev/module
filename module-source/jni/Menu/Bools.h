/*Bools*/
bool open_menu,setup,esp_enable ;
bool scale_enable,airjump_enable,masskill_enable,telekill_enable;
float scale = 1.9f;
	bool draw_box, draw_line,esp_health,draw_nick,esp_distance;
int cornedbox = 0.7;
ImVec4  BoxColor = { 1, 1, 1, 1 };
 
ImVec4  LineColor = { 1, 1, 1, 1 };

ImVec4  MoneyColor = { 0,1,0,1 };

ImVec4  DistColor = { 1, 1, 0, 1 };
bool outoffov;
bool oofvis;
std::map<void*, bool>visiblechecker;
bool visible;
float dpiscale = 1.50f;       
ImVec4 accentCol = ImVec4(1.0f, 0, 0, 1.0f);
void *me_player;
void *enemy_player;
static std::vector<PlayerController*>players;
static std::vector<Camera*>cameras;
static bool esptest=false;

/*end*/
