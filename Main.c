//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include <Stdio.h>
extern int g_iGameState;
extern int n;
const char xuanren[8][20]={"xuanren_d","xuanren_a","xuanren_stopd","xuanren_stopa","xuanren_jd","xuanren_ja","xuanren_wd","xuanren_wa",};
const char   name[4][20]={ "kaishiyouxi",  "beijinggushi" , "wanfajieshao","tuichuyouxi"};
const char dierguanzhangaiwu[8][20]={"dierguanzuo1","dierguanzuo2","dierguanzuo3","dierguanzuo4","dierguanzuo5","dierguankong1","dierguankong2","dierguankong3"};
const char diyiguanzhangaiwu[8][20]={"diyiguanzuo1","diyiguanzuo2","diyiguanzuo3","diyiguanzuo4","diyiguankong1","diyiguankong2","diyiguankong3","diyiguankong4"};
const char disanguanzhangaiwu[1][20]={"disanguandimian"};
const char qiangdaonv[4][15]={"qiangdaonv1","qiangdaonv2","qiangdaonv3","qiangdaonv4"};
const char qiangdaonan[4][15]={"qiangdaonan1","qiangdaonan2","qiangdaonan3","qiangdaonan4"};
const char she[3][5]={"she1","she2","she3"};
const char xiezi[3][10]={"xiezi1","xiezi2","xiezi3"};
const char xiaobing1[3][15]={"xiaobing11","xiaobing12","xiaobing13"};
const char xiaobing2[3][15]={"xiaobing21","xiaobing22","xiaobing23"};
const char baojianheng[4][20]={"baojianheng1","baojianheng2","baojianheng3","baojianheng4"};
const char baojianshu[4][20]={"baojianshu1","baojianshu2","baojianshu3","baojianshu4"};
const char niao[4][10]={"niao1","niao2","niao3","niao4"};
const char jian[4][10]={"jian1","jian2","jian3","jian4"};
const char bing[2][15]={"bing1","bing2"};
float g_fScreenLeft		=	0.f;    // 屏幕左边界值
float g_fScreenRight	=	0.f;    // 右
float g_fScreenTop		=	0.f;    // 上
float g_fScreenBottom	=	0.f;    // 下
extern int dierguanjinglinggeshu;
extern int diyiguanjinglinggeshu;
float	fSpeedX=0.f, fSpeedY=0.f;
///////////////////////////////////////////////////////////////////////////////////////////
//
// 主函数入口
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	int shedegeshu;
	// 初始化游戏引擎
	if( !dInitGameEngine( hInstance, lpCmdLine ) )
		return 0;
	g_fScreenLeft	 = 	dGetScreenLeft();
	g_fScreenRight  = 	dGetScreenRight();
	g_fScreenTop 	 = 	dGetScreenTop();
	g_fScreenBottom = 	dGetScreenBottom();

	// To do : 在此使用API更改窗口标题
	dSetWindowTitle("Lesson");
	
	// 引擎主循环，处理屏幕图像刷新等工作
	while( dEngineMainLoop() )
	{
		// 获取两次调用之间的时间差，传递给游戏逻辑处理
		float	fTimeDelta	=	dGetTimeDelta();

		// 执行游戏主循环
		GameMainLoop( fTimeDelta );
	};

	// 关闭游戏引擎
	dShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	OnMouseMove(fMouseX, fMouseY );
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	OnMouseClick( iMouseType, fMouseX, fMouseY );	
	
}
//==========================================================================
//
// 引擎捕捉鼠标弹起消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	OnMouseUp(iMouseType, fMouseX, fMouseY);
		
}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
//
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
	// 可以在此添加游戏需要的响应函数
	OnKeyDown(iKey, iAltPress, iShiftPress, iCtrlPress);
	if((n==12)||(n==7)||(n==19)||(n==22))
	{
		switch(iKey)
		{
			case KEY_W:		
				fSpeedY = -15.f;
				if(dIsSpriteVisible( "xuanren_d" )||dIsSpriteVisible( "xuanren_stopd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 1 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_a" )||dIsSpriteVisible( "xuanren_stopa" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_wa", 1 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
				break;
			case KEY_A:
				fSpeedX = -15.f;
				dSetSpriteVisible( "xuanren_stopd", 0 );
				dSetSpriteVisible( "xuanren_d", 0 );
				dSetSpriteVisible( "xuanren_jd", 0 );
				dSetSpriteVisible( "xuanren_wa", 0 );
				dSetSpriteVisible( "xuanren_wd", 0 );
				dSetSpriteVisible( "xuanren_ja", 0 );
				dSetSpriteVisible( "xuanren_stopa", 0 );
				dSetSpriteVisible( "xuanren_a", 1 );
				dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
				break;
			case KEY_S:		
				fSpeedY = 15.f;
				if(dIsSpriteVisible( "xuanren_d" )||dIsSpriteVisible( "xuanren_stopd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 1 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_a" )||dIsSpriteVisible( "xuanren_stopa" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_wa", 1 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
				break;
			case KEY_D:
				fSpeedX = 15.f;	
				dSetSpriteVisible( "xuanren_stopd", 0 );
				dSetSpriteVisible( "xuanren_d", 1 );
				dSetSpriteVisible( "xuanren_jd", 0 );
				dSetSpriteVisible( "xuanren_ja", 0 );
				dSetSpriteVisible( "xuanren_wa", 0 );
				dSetSpriteVisible( "xuanren_wd", 0 );
				dSetSpriteVisible( "xuanren_stopa", 0 );
				dSetSpriteVisible( "xuanren_a", 0 );
				dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
				break;
			case KEY_J:
				fSpeedX = 0.f;
				dPlaySound("5784", 0, 1 );
				if(dIsSpriteVisible( "xuanren_d" )||dIsSpriteVisible( "xuanren_stopd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 1 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_a" )||dIsSpriteVisible( "xuanren_stopa" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 1 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
				dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
		}
	}
}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
//
void dOnKeyUp( const int iKey )
{
	// 可以在此添加游戏需要的响应函数
	OnKeyUp(iKey);
	if((n==12)||(n==7)||(n==19)||(n==22))
	{
		switch(iKey)
		{
			case KEY_W:		
				fSpeedY = 0.f;
				if(dIsSpriteVisible( "xuanren_wd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 1 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_wa" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 1 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				break;
			case KEY_A:
				fSpeedX = 0.f;	
				dSetSpriteVisible( "xuanren_stopd", 0 );
				dSetSpriteVisible( "xuanren_d", 0 );
				dSetSpriteVisible( "xuanren_stopa", 1 );
				dSetSpriteVisible( "xuanren_a", 0 );
				dSetSpriteVisible( "xuanren_ja", 0 );
				dSetSpriteVisible( "xuanren_jd", 0 );
				dSetSpriteVisible( "xuanren_wa", 0 );
				dSetSpriteVisible( "xuanren_wd", 0 );
				break;
			case KEY_S:		
				fSpeedY = 0.f;
				if(dIsSpriteVisible( "xuanren_wd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 1 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_wa" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_wa", 0 );
					dSetSpriteVisible( "xuanren_wd", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 1 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				break;
			case KEY_D:
				fSpeedX = 0.f;	
				dSetSpriteVisible( "xuanren_stopd", 1 );
				dSetSpriteVisible( "xuanren_d", 0 );
				dSetSpriteVisible( "xuanren_stopa", 0 );
				dSetSpriteVisible( "xuanren_a", 0 );
				dSetSpriteVisible( "xuanren_ja", 0 );
				dSetSpriteVisible( "xuanren_jd", 0 );
				dSetSpriteVisible( "xuanren_wa", 0 );
				dSetSpriteVisible( "xuanren_wd", 0 );
				break;
			case KEY_J:
				fSpeedX = 0.f;	
				if(dIsSpriteVisible( "xuanren_jd" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 1 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 0 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				if(dIsSpriteVisible( "xuanren_ja" ))
				{
					dSetSpriteVisible( "xuanren_jd", 0 );
					dSetSpriteVisible( "xuanren_stopd", 0 );
					dSetSpriteVisible( "xuanren_d", 0 );
					dSetSpriteVisible( "xuanren_ja", 0 );
					dSetSpriteVisible( "xuanren_stopa", 1 );
					dSetSpriteVisible( "xuanren_a", 0 );
				}
				break;
				
			}
			dSetSpriteLinearVelocity("xuanren_d", fSpeedX, fSpeedY);
	        dSetSpriteLinearVelocity("xuanren_stopd", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_a", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_stopa", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_ja", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_jd", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_wa", fSpeedX, fSpeedY);
			dSetSpriteLinearVelocity("xuanren_wd", fSpeedX, fSpeedY);
	}
}
//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵发送及接受碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
//
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	OnSpriteColSprite( szSrcName, szTarName );
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵的世界边界限制
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
//
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// 可以在此添加游戏需要的响应函数
	OnSpriteColWorldLimit(szName, iColSide);
	int geshu;
	if(n==12)
	{
		for(geshu=0;geshu<3;geshu++)
		{
			dSetSpriteWorldLimit(xiezi[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, xiezi[geshu])==0)
			{
				if(iColSide == 1)  // 右边
				{
					dSetSpriteFlipX(xiezi[geshu], true);
					dSetSpriteLinearVelocity(xiezi[geshu], -20, 0);
				}
				else if(iColSide == 0)   // 左边
				{
					dSetSpriteFlipX(xiezi[geshu], false);
					dSetSpriteLinearVelocity(xiezi[geshu], 20, 0);
				}		
			}
			dSetSpriteWorldLimit(she[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, she[geshu])==0)
			{
				if(iColSide == 1)  // 右边
				{
					dSetSpriteFlipX(she[geshu], true);
					dSetSpriteLinearVelocity(she[geshu], -20, 0);
				}
				else if(iColSide == 0)   // 左边
				{
					dSetSpriteFlipX(she[geshu], false);
					dSetSpriteLinearVelocity(she[geshu], 20, 0);
				}		
			}
		}
	}
	if(n==7)
	{
		for(geshu=0;geshu<3;geshu++)
		{
			dSetSpriteWorldLimit(qiangdaonv[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, qiangdaonv[geshu])==0)
			{
				if(iColSide == 1)  // 右边
				{
					dSetSpriteFlipX(qiangdaonv[geshu], true);
					dSetSpriteLinearVelocity(qiangdaonv[geshu], -20, 0);
				}
				else if(iColSide == 0)   // 左边
				{
					dSetSpriteFlipX(qiangdaonv[geshu], false);
					dSetSpriteLinearVelocity(qiangdaonv[geshu], 20, 0);
				}		
			}
			dSetSpriteWorldLimit(qiangdaonan[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, qiangdaonan[geshu])==0)
			{
				if(iColSide == 0)  // zuo边
				{
					dSetSpriteFlipX(qiangdaonan[geshu], true);
					dSetSpriteLinearVelocity(qiangdaonan[geshu], 20, 0);
				}
				else if(iColSide == 1)   // you边
				{
					dSetSpriteFlipX(qiangdaonan[geshu], false);
					dSetSpriteLinearVelocity(qiangdaonan[geshu], -20, 0);
				}		
			}
		}
	}
	if(n==19)
	{
		for(geshu=0;geshu<3;geshu++)
		{
			dSetSpriteWorldLimit(xiaobing1[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, xiaobing1[geshu])==0)
			{
				if(iColSide == 0)  // zuo边
				{
					dSetSpriteFlipX(xiaobing1[geshu], true);
					dSetSpriteLinearVelocity(xiaobing1[geshu], 20, 0);
				}
				else if(iColSide == 1)   // you边
				{
					dSetSpriteFlipX(xiaobing1[geshu], false);
					dSetSpriteLinearVelocity(xiaobing1[geshu], -20, 0);
				}		
			}
			dSetSpriteWorldLimit(xiaobing2[geshu], WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
			if(strcmp(szName, xiaobing2[geshu])==0)
			{
				if(iColSide == 0)  // zuo边
				{
					dSetSpriteFlipX(xiaobing2[geshu], true);
					dSetSpriteLinearVelocity(xiaobing2[geshu], 20, 0);
				}
				else if(iColSide == 1)   // you边
				{
					dSetSpriteFlipX(xiaobing2[geshu], false);
					dSetSpriteLinearVelocity(xiaobing2[geshu], -20, 0);
				}		
			}
		}
	}
}
