#pragma once
#include "Singleton.h"

enum class eImageTag
{
	// 캐릭터
	Char_shadow, Jiwoo_idle, Jiwoo_moveUD, Jiwoo_moveRL, DoctorO,
	SubO, Mom_move, Mom_idle, Mart, Nurse, Master, Master_sub, DoctorOBig,

	// 포켓몬
	Caterpie_R, Caterpie_F, Dandegi_R, Dandegi_F, Butter_R, Butter_F,
	Bbul_R, Bbul_F, Ddak_R, Ddak_F, DokChung_R, DokChung_F, Gugu_R, Gugu_F,
	Pigeon_R, Pigeon_F, PigeonTwo_R, PigeonTwo_F, Ggorat_R, Ggorat_F,
	Rat_R, Rat_F, Ggaebi_R, Ggaebi_F, Ggaebidrill_R, Ggaebidrill_F, Pika_R, Pika_F,
	Richu_R, Richu_F, Chicorita_R, Chicorita_F, Bayleaf_R, Bayleaf_F,
	Meganium_R, Meganium_F, Bcane_R, Bcane_F, Riaco_R, Riaco_F, Alligay_R, Alligay_F,
	Jangcro_R, Jangcro_F,

	// 배경
	StartRoom, Background,

	// 타일
	SampleTile, DrawTile,

	// 타입이미지
	PokeIcon,

	// Dialogue UI
	Dialogue,

	// Menu UI
	BlackBack, Dogam, Gear, GearMinimap, Gear1, MenuDogam, MenuPoke, MenuBag, MenuGear,
	MenuPlayer, MenuSet, MenuClose, DetectPoke, WhiteCursor,

	PokeSelect1, PokeSelect2, PokeSelect3, PokeSelect4, PokeSelect5, PokeSelect6, PokeSelectCls,
	PokePower, Setting, SettingCLs,
	Status, Status1,
	CursorRight, CursorBottom, DogamSelect,

	// Battle UI
	BattleLoading, BattleFlash,  BattleFrame, BattleSkill, BattleSelect, Gender, HpBar, ExpGauge, HpGauge, HpGaugeBack,
	ExpGaugeBack, PlayerImg, PokeBallState,

	// Shop UI
	BuyMonsterBall, Medi, SuperMedi, ShopCls, Buy, Sell, Nothing,

	// PokemonCenter
	HealingPoke,

	// Particle
	AppearPoke, Attack, Attack3, Bind, Cut, Cut3, fire, Growth, Horn, Light, Move, MyConfusion, 
	MyHorn, MyPoison, MyQuickAttack, MySandAttack, MyStringShot, Poison, RazorWind, Shine, Shock, 
	SkyAttack, Slash, SmokeScreen, Snap, Spark, Squall, WildConfusion, WildHorn, WildPoisonSting, 
	WildQuickAttack, WildSandAttack, WildStingShot, WalkGrass1, WalkGrass2, Shadow,

	// End Scene
	End1, End2, End3, End4, EndPoke1, EndPoke2, EndPoke3, EndPoke4,




};

class Image;
class ImageManager : public Singleton<ImageManager>
{
private:
	map<eImageTag, Image*>	mapImages;
	map<int, Image*> mapChunkImages;

public:

	void Init();
	void Release();

	Image* AddImage(eImageTag tag, const char* fileName, int width, int height,
		bool isTrans = false, COLORREF transColor = NULL);	// 사용할 이미지를 등록하는 기능

	Image* AddImage(eImageTag tag, const char* fileName, int width, int height,
		int maxFrameX, int maxFrameY,
		bool isTrans = false, COLORREF transColor = NULL);

	Image* AddImage(int index, const char* fileName, int width, int height,
		bool isTrans = false, COLORREF transColor = NULL); // 오프닝 이미지 추가

	Image* FindImage(eImageTag tag);	// 등록된 이미지 중에 필요한 이미지를 찾는 기능
	Image* FindImage(int index);
	void DeleteImage(eImageTag tag);	// 사용이 종료된 이미지를 등록 해제하는 기능
	void DeleteImage(int index);
};

