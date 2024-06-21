#include "Env.h"

int Env::course = 1;    // Lコースが1, Rコースが2(1以外)
int Env::white_r = 176; // 白地R値のデフォルト値
int Env::white_g = 164; // 白地G値のデフォルト値
int Env::white_b = 127; // 白地B値のデフォルト値
int Env::black_r = 10;   // 黒ラインR値のデフォルト値
int Env::black_g = 10;  // 黒ラインG値のデフォルト値
int Env::black_b = 10;   // 黒ラインB値のデフォルト値
int Env::block_pattern = 1; // ブロック配置パターン1～5
bool Env::red_block_found = false;    // 赤ブロックを見つけたときtrue(デフォルトfalse)
