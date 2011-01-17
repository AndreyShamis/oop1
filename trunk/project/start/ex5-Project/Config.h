
#define FENCE	'#'
#define LANE	' '
#define BARREL	'O'
#define MAPS_FOLDER			"MAPS"
#define RGBA_SIZE			"28x28_alfa"
#define RGBA_FOLDER			"RGBA"



//surprises
#define SURPRISE_BOMB		"bomb_surprise_rgba.txt"
#define SURPRISE_TIME		"clock_rgba.txt"
#define SURPRISE_LIHT		"light_rgba.txt"

//	bomb add time
#define BOMB_TIMER_INCREASER 30

//present tipes
#define PRESENT_BOMB		1
#define PRESENT_TIME		2
#define PRESENT_LIGHT		3

//levels
#define LEVEL_1_PIC			"level1_rgba.txt"
#define LEVEL_2_PIC			"level2_rgba.txt"
#define LEVEL_3_PIC			"level3_rgba.txt"
#define LEVEL_4_PIC			"level4_rgba.txt"
#define LEVEL_5_PIC			"level5_rgba.txt"
#define MAX_LEVEL			5
//menu
#define MENU_LOSE			"loser_score_rgba.txt"

#define MENU_USR_L_1		"player_score_1_rgba.txt"
#define MENU_USR_L_2		"player_score_2_rgba.txt"
#define MENU_USR_L_3		"player_score_3_rgba.txt"

#define MENU_ENM_L_1		"enemy_score_1_rgba.txt"
#define MENU_ENM_L_2		"enemy_score_2_rgba.txt"
#define MENU_ENM_L_3		"enemy_score_3_rgba.txt"


#define SPACE				"space_rgba.txt"
#define SURPRISE			"surprise_rgba.txt"
#define WALL				"brich_wall_rgba.txt"
#define ENEMY_D				"enemy.down_rgba.txt"
#define ENEMY_L				"enemy.left_rgba.txt"
#define ENEMY_R				"enemy.right_rgba.txt"
#define ENEMY_U				"enemy.up_rgba.txt"
#define PLAYER_D			"Player.down_rgba.txt"
#define PLAYER_L			"Player.left_rgba.txt"
#define PLAYER_R			"Player.right_rgba.txt"
#define PLAYER_U			"Player.up_rgba.txt"
#define EXP_VER				"explosion_vertical_rgba.txt"
#define EXP_UP				"explosion_up_rgba.txt"
#define EXP_START			"explosion_start_rgba.txt"
#define EXP_RIGHT			"explosion_right_rgba.txt"
#define EXP_LEFT			"explosion_left_rgba.txt"
#define EXP_HOR				"explosion_horizontal_rgba.txt"
#define EXP_DOWN			"explosion_down_rgba.txt"
#define EXP_VER_USR			"explosion_vertical_user_rgba.txt"
#define EXP_UP_USR			"explosion_up_user_rgba.txt"
#define EXP_START_USR		"explosion_start_user_rgba.txt"
#define EXP_DOWN_USR		"explosion_down_user_rgba.txt"
#define EXP_RIGHT_USR		"explosion_right_user_rgba.txt"
#define EXP_LEFT_USR		"explosion_left_user_rgba.txt"
#define EXP_HOR_USR			"explosion_horizontal_user_rgba.txt"
#define BOMB_BEFOR			"bomb.one.step.befor.explogen_rgba.txt"
#define BOMB_STEP_ONE		"bomb_step_one_rgba.txt"
#define BOMB_STEP_TWO		"bomb_step_two_rgba.txt"

#define BOMB_STEP_TWO_USR	"bomb_step_two_user_rgba.txt"
#define BOMB_STEP_ONE_USR	"bomb_step_one_user_rgba.txt"
#define BOMB_BEFOR_USR		"bomb.one.step.befor.explosion.user_rgba.txt"


#define MAX_BOMB_COMP		100			
#define LIMIT_BOMB_COMP		20	
#define STEP_SPEED 7

#define PIC_WIDTH 28
struct Vertex
{
	float _x;
	float _y;
};

struct RGBA{
	short int  _r, _g, _b, _a;
};