
#define FENCE	'#'
#define LANE	' '
#define BARREL	'O'

#define RGBA_SIZE	"28x28"
#define RGBA_FOLDER "RGBA"


#define BOMB_BEFOR		"bomb.one.step.befor.explogen_rgba.txt"
#define BOMB_STEP_ONE	"bomb_step_one_rgba.txt"
#define BOMB_STEP_TWO	"bomb_step_two_rgba.txt"
#define BOMB_SURPRISE	"bomb_surprise_rgba.txt"
#define WALL			"brich_wall_rgba.txt"
#define ENEMY_D			"enemy.down_rgba.txt"
#define ENEMY_L			"enemy.left_rgba.txt"
#define ENEMY_R			"enemy.right_rgba.txt"
#define ENEMY_U			"enemy.up_rgba.txt"
#define PLAYER_D		"Player.down_rgba.txt"
#define PLAYER_L		"Player.left_rgba.txt"
#define PLAYER_R		"Player.right_rgba.txt"
#define PLAYER_U		"Player.up_rgba.txt"
#define SPACE			"space_rgba.txt"
#define SURPRISE		"surprise_rgba.txt"




struct Vertex
{
	float _x;
	float _y;
};

struct RGBA{
	short int  _r, _g, _b, _a;
};