#pragma once

#include <string>
#include <map>


//========================================//
// ライブラリ読み込み
//========================================//
#ifdef _DEBUG
#	pragma comment( lib, "impulse_d.lib" )
#else
#	pragma comment( lib, "impulse_r.lib" )
#endif

//========================================//
// プロパティ
//========================================//
#define PROPERTY( _TAG_, _ARG_ ) \
class Peoperty##_TAG_ : public Property { \
public: virtual ~Peoperty##_TAG_ ( ) {} \
Peoperty##_TAG_ ( ) { set( #_TAG_, #_ARG_ ); } \
} __##Peoperty##_TAG_##__

#define GAME_BEGIN( _TITLE_ ) \
class _TITLE_ : public Game { \
public: \
	_TITLE_##( ) : Game( #_TITLE_ ) { } \
	virtual ~##_TITLE_##( ) { }

#define GAME_END \
} __game__;


//========================================//
// アセット
//========================================//
enum class ASSET {
	BUTTON,
	HAZARD,
	MARK,
	MARBLE,
	SCREEN,
	NUMBER,
	FRAME,
	PLATE,
	BACKGROUND,
};

enum class STOPWATCH {
	START,
	STOP
};

//========================================//
// SE
//========================================//
enum class SE {
	HIT,
	MISS,
	SET,
};

//========================================//
// コマンド
//========================================//
enum class CMD {
	POS_X,
	POS_Y,
	STATUS,
	TOUCH,
	VISIBLE,
	WIDTH,
	HEIGHT,
	PRIORITY,
};

//========================================//
// ステータス
//========================================//
const int BUTTON_NORMAL     = 0x1000;
const int BUTTON_TURNON     = 0x1001;
const int BUTTON_DISABLED   = 0x1002;

const int MARBLE_BREAK	    = 0x2000;

const int CN_MARK_DRINK     = 0x3001;
const int CN_MARK_SHOES     = 0x3002;
const int CN_MARK_WATCH     = 0x3003;
const int CN_MARK_MISANGA   = 0x3004;

const int SUP_MARK_CLUB     = 0x4001;
const int SUP_MARK_DIA      = 0x4002;
const int SUP_MARK_HEAT     = 0x4003;
const int SUP_MARK_SPADE    = 0x4004;

const int SUP_MARK_UP       = 0x4005;
const int SUP_MARK_DOWN     = 0x4006;
const int SUP_MARK_LEFT     = 0x4007;
const int SUP_MARK_RIGHT    = 0x4008;
const int SUP_MARK_MARU     = 0x4009;
const int SUP_MARK_BATU     = 0x4010;

const int PLATE_THEME       = 0x5001;
const int PLATE_REMAINING   = 0x5002;

//========================================//
// 画面サイズ
//========================================//
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//========================================//
// 画面サイズ
//========================================//
const int CHIP_SIZE = 136;

//========================================V//
// property
//========================================//
class Property {
public:
	Property( ) { }
	virtual ~Property( ) { }
protected:
	static void set( const char * tag, const char * arg );
};

//========================================//
// game.cpp
//========================================//
class Game {
public:
	Game( const char * tag );
	virtual ~Game( );
	virtual void setup( ) { }
	virtual void update( ) { }
};

//========================================//
// メソッド
//========================================//
int  createAsset( ASSET asset );					// アセットの生成
void destroyAsset( int id );						// アセットの破棄
void setAsset(int id, CMD cmd, int value );			// コマンドセット
int getAsset(int id, CMD cmd);						// コマンドゲット
int  random( );										// ランダム値の取得
void finish( );							            // 終了
void stopwatch( STOPWATCH sw );                     // ストップウォッチコントロール
void playSe( SE se );								// SEの再生
void consoleWrite( const char* format, ... );       //Debug用
