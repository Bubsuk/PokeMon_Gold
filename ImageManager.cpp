#include "stdafx.h"
#include "Config.h"
#include "ImageManager.h"
#include "Image.h"

void ImageManager::Init()
{
	// 캐릭터
	//AddImage(eImageTag::Jiwoo_idle, "Image/Jiwoo_idle.bmp", 128, 128, 2, 2, true, RGB(255, 0, 255));
	AddImage(eImageTag::Jiwoo_moveUD, "Image/Jiwoo_UD.bmp", 280, 128, 5, 2, true, RGB(255, 0, 255));
	AddImage(eImageTag::Jiwoo_moveRL, "Image/Jiwoo_RL.bmp", 171, 128, 3, 2, true, RGB(255, 0, 255));
	AddImage(eImageTag::DoctorO, "Image/pokemon_O.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::SubO, "Image/pokemon_Ominion.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Mom_move, "Image/mom_move.bmp", 128, 128, 2, 2, true, RGB(255, 0, 255));
	//AddImage(eImageTag::Mom_idle, "Image/mom_move.bmp", 128, 128, 2, 2, true, RGB(255, 0, 255));
	AddImage(eImageTag::Mart, "Image/pokemon_mart.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Nurse, "Image/pokemon_nurse.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Master, "Image/pokemon_master.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Master_sub, "Image/master_sub.bmp", 128, 64, 2, 1, true, RGB(255, 0, 255));
	
	// 포켓몬
	AddImage(eImageTag::Caterpie_R, "Image/pokemon/no_10B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Caterpie_F, "Image/pokemon/no_10F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Dandegi_R, "Image/pokemon/no_11B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Dandegi_F, "Image/pokemon/no_11F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Butter_R, "Image/pokemon/no_12B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Butter_F, "Image/pokemon/no_12F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bbul_R, "Image/pokemon/no_13B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bbul_F, "Image/pokemon/no_13F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ddak_R, "Image/pokemon/no_14B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ddak_F, "Image/pokemon/no_14F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::DokChung_R, "Image/pokemon/no_15B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::DokChung_F, "Image/pokemon/no_15F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Gugu_R, "Image/pokemon/no_16B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Gugu_F, "Image/pokemon/no_16F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Pigeon_R, "Image/pokemon/no_17B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Pigeon_F, "Image/pokemon/no_17F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::PigeonTwo_R, "Image/pokemon/no_18B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::PigeonTwo_F, "Image/pokemon/no_18F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggorat_R, "Image/pokemon/no_19B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggorat_F, "Image/pokemon/no_19F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Rat_R, "Image/pokemon/no_20B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Rat_F, "Image/pokemon/no_20F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggaebi_R, "Image/pokemon/no_21B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggaebi_F, "Image/pokemon/no_21F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggaebidrill_R, "Image/pokemon/no_22B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Ggaebidrill_F, "Image/pokemon/no_22F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Pika_R, "Image/pokemon/no_25B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Pika_F, "Image/pokemon/no_25F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Richu_R, "Image/pokemon/no_26B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Richu_F, "Image/pokemon/no_26F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Chicorita_R, "Image/pokemon/no_152B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Chicorita_F, "Image/pokemon/no_152F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bayleaf_R, "Image/pokemon/no_153B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bayleaf_F, "Image/pokemon/no_153F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Meganium_R, "Image/pokemon/no_154B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Meganium_F, "Image/pokemon/no_154F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bcane_R, "Image/pokemon/no_155B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Bcane_F, "Image/pokemon/no_155F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Riaco_R, "Image/pokemon/no_158B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Riaco_F, "Image/pokemon/no_158F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Alligay_R, "Image/pokemon/no_159B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Alligay_F, "Image/pokemon/no_159F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Jangcro_R, "Image/pokemon/no_160B.bmp", 192, 192, 1, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::Jangcro_F, "Image/pokemon/no_160F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));

	// 포켓몬 타입이미지
	AddImage(eImageTag::PokeIcon, "Image/menuUI/pokeicon.bmp", 2048, 191, 32, 3, true, RGB(255, 0, 255));

	// 배경
	AddImage(eImageTag::StartRoom, "Image/pokemon_start_home1.bmp", 640, 512);
	AddImage(eImageTag::Background, "Image/mapImage.bmp", 1024, 768);

	// 타일
	AddImage(eImageTag::SampleTile, "Image/pokemon_tile.bmp", 600, 600, 15, 15, true, RGB(255, 0, 255));
	AddImage(eImageTag::DrawTile, "Image/pokemon_tile.bmp", 960, 960, 15, 15, true, RGB(255, 0, 255));

	// UI - OPENNING
	for (int i = 0; i < 112; ++i)
	{
		static int num = 0;
		char address[100];
		++num;
		string str = "Image/op_image/op_";
		str += to_string(num);
		str += ".bmp";
		strcpy_s(address, str.c_str());
		AddImage(num, address, 640, 576);
	}


	// UI - MENU
	AddImage(eImageTag::DetectPoke, "Image/pokemon_mark.bmp", 32, 32);
	AddImage(eImageTag::Dogam, "Image/menuUI/dogam_0.bmp", 650, 576);
	AddImage(eImageTag::Gear, "Image/menuUI/gear_0.bmp", 650, 576);
	AddImage(eImageTag::GearMinimap, "Image/menuUI/gear_1.bmp", 650, 576);
	AddImage(eImageTag::Gear1, "Image/menuUI/gear_2.bmp", 650, 576);

	AddImage(eImageTag::MenuDogam, "Image/menuUI/menu_1.bmp", 257, 576);
	AddImage(eImageTag::MenuPoke, "Image/menuUI/menu_2.bmp", 257, 576);
	AddImage(eImageTag::MenuBag, "Image/menuUI/menu_3.bmp", 257, 576);
	AddImage(eImageTag::MenuGear, "Image/menuUI/menu_4.bmp", 257, 576);
	AddImage(eImageTag::MenuPlayer, "Image/menuUI/menu_5.bmp", 257, 576);
	AddImage(eImageTag::MenuSet, "Image/menuUI/menu_6.bmp", 257, 576);
	AddImage(eImageTag::MenuClose, "Image/menuUI/menu_7.bmp", 257, 576);
	
	
	AddImage(eImageTag::PokeSelect1, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelect2, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelect3, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelect4, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelect5, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelect6, "Image/menuUI/pokeShift_0.bmp", 650, 576);
	AddImage(eImageTag::PokeSelectCls, "Image/menuUI/pokeShift_0.bmp", 650, 576);

	AddImage(eImageTag::PokePower, "Image/menuUI/power_0.bmp", 650, 576);

	AddImage(eImageTag::Setting, "Image/menuUI/setting_0.bmp", 650, 576);
	AddImage(eImageTag::SettingCLs, "Image/menuUI/setting_1.bmp", 650, 576);

	AddImage(eImageTag::Status, "Image/menuUI/status_0.bmp", 650, 576);
	AddImage(eImageTag::Status1, "Image/menuUI/status_1.bmp", 650, 576);

	AddImage(eImageTag::CursorRight, "Image/battle/cursorBehavior.bmp", 32, 32);
	AddImage(eImageTag::CursorBottom, "Image/battle/cursorBottom.bmp", 32, 32);
	AddImage(eImageTag::DogamSelect, "Image/menuUI/dogam_select.bmp", 226, 62, true, RGB(255, 0, 255));


	// UI - Battle
	AddImage(eImageTag::Gender, "Image/battle_loading.bmp", 17920, 596, 28, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::BattleFlash, "Image/battle/flash_loading.bmp", 640, 576);
	AddImage(eImageTag::BattleFrame, "Image/battle/battleBackground.bmp", 640, 576);
	AddImage(eImageTag::BattleSkill, "Image/battle/backgroundSkill.bmp", 640, 289);
	AddImage(eImageTag::BattleSelect, "Image/battle/selectBehavior.bmp", 640, 186);
	AddImage(eImageTag::Gender, "Image/battle/gender.bmp", 7, 16, 1, 2, true, RGB(255, 0, 255));
	AddImage(eImageTag::HpBar, "Image/battle/hpBar.bmp", 272, 24);
	AddImage(eImageTag::ExpGauge, "Image/battle/expGauge.bmp", 256, 8);
	AddImage(eImageTag::HpGauge, "Image/battle/hpGauge.bmp", 192, 8);
	AddImage(eImageTag::HpGaugeBack, "Image/battle/cursorBottom.bmp", 192, 8);
	AddImage(eImageTag::ExpGaugeBack, "Image/battle/expGaugeBack.bmp", 192, 8);
	AddImage(eImageTag::PlayerImg, "Image/battle/playerImage.bmp", 188, 192);
	AddImage(eImageTag::PokeBallState, "Image/battle/pokeballState.bmp", 28, 112, 1, 4, true, RGB(255, 0, 255));
	AddImage(eImageTag::AppearPoke, "Image/battle/appearPokemon.bmp", 600, 200);

	// UI - Shop
	AddImage(eImageTag::HealingPoke, "Image/battle/appearPokemon.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));
	AddImage(eImageTag::BuyMonsterBall, "Image/shopUI/buy_1.bmp", 650, 576);
	AddImage(eImageTag::Medi, "Image/shopUI/buy_2.bmp", 650, 576);
	AddImage(eImageTag::SuperMedi, "Image/shopUI/buy_3.bmp", 650, 576);
	AddImage(eImageTag::ShopCls, "Image/shopUI/buy_4.bmp", 650, 576);
	AddImage(eImageTag::Buy, "Image/shopUI/shop_1.bmp", 650, 576);
	AddImage(eImageTag::Sell, "Image/shopUI/shop_2.bmp", 650, 576);
	AddImage(eImageTag::Nothing, "Image/shopUI/shop_3.bmp", 650, 576);

	// Particle
	AddImage(eImageTag::WalkGrass1, "Image/poketmon_grass1.bmp", 48, 36);
	AddImage(eImageTag::WalkGrass2, "Image/poketmon_grass2.bmp", 45, 21);
	AddImage(eImageTag::Shadow, "Image/character_shadow.bmp", 56, 64, 1, 1, true, RGB(255, 0, 255));


	// End Scene
	AddImage(eImageTag::End1, "Image/end_image/endingBackground1.bmp", 650, 576);
	AddImage(eImageTag::End2, "Image/end_image/endingBackground2.bmp", 650, 576);
	AddImage(eImageTag::End3, "Image/end_image/endingBackground3.bmp", 650, 576);
	AddImage(eImageTag::End4, "Image/end_image/endingBackground4.bmp", 650, 576);
	AddImage(eImageTag::EndPoke1, "Image/end_image/endingPokemon1.bmp", 192, 68);
	AddImage(eImageTag::EndPoke2, "Image/end_image/endingPokemon1.bmp", 192, 68);
	AddImage(eImageTag::EndPoke3, "Image/end_image/endingPokemon1.bmp", 192, 68);
	AddImage(eImageTag::EndPoke4, "Image/end_image/endingPokemon1.bmp", 192, 68);

	// Dialogue UI
	AddImage(eImageTag::Dialogue, "Image/dialogueUI.bmp", 192, 68);


}

void ImageManager::Release()
{
	map<eImageTag, Image*>::iterator it;
	for (it = mapImages.begin(); it != mapImages.end();)
	{
		SAFE_RELEASE(it->second);
		it = mapImages.erase(it);	// 다음 원소의 주소(iterator)가 갱신된다.
	}
	mapImages.clear();

	map<int, Image*>::iterator iter;
	for (iter = mapChunkImages.begin(); iter != mapChunkImages.end();)
	{
		SAFE_RELEASE(iter->second);
		iter = mapChunkImages.erase(iter);	// 다음 원소의 주소(iterator)가 갱신된다.
	}
	mapImages.clear();
}

Image* ImageManager::AddImage(eImageTag tag, const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// 이미 등록한 이미지는 nullptr을 반환
	if (mapImages.find(tag) != mapImages.end()) { return nullptr; }

	Image* img = new Image;
	if (FAILED(img->Init(fileName, width, height, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapImages.insert(make_pair(tag, img));

	return img;
}

Image* ImageManager::AddImage(eImageTag tag, const char* fileName, int width, int height,
	int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	// 이미 등록한 이미지는 nullptr을 반환
	if (mapImages.find(tag) != mapImages.end()) { return nullptr; }

	Image* img = new Image;
	if (FAILED(img->Init(fileName, width, height, maxFrameX,
		maxFrameY, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapImages.insert(make_pair(tag, img));

	return img;
}

Image* ImageManager::AddImage(int index, const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// 이미 등록한 이미지는 nullptr을 반환
	if (mapChunkImages.find(index) != mapChunkImages.end()) { return nullptr; }

	Image* img = new Image;
	if (FAILED(img->Init(fileName, width, height, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapChunkImages.insert(make_pair(index, img));

	return img;
}


Image* ImageManager::FindImage(eImageTag tag)
{
	map<eImageTag, Image*>::iterator it = mapImages.find(tag);
	if (it == mapImages.end())
	{
		return nullptr;
	}

	return it->second;
}

Image* ImageManager::FindImage(int index)
{
	map<int, Image*>::iterator it = mapChunkImages.find(index);
	if (it == mapChunkImages.end())
	{
		return nullptr;
	}

	return it->second;
}

void ImageManager::DeleteImage(eImageTag tag)
{
	map<eImageTag, Image*>::iterator it = mapImages.find(tag);
	if (it == mapImages.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);	// Image*	// Image 동적할당 해제
	mapImages.erase(it);		// 맵에서 노드 삭제
}

void ImageManager::DeleteImage(int index)
{
	map<int, Image*>::iterator it = mapChunkImages.find(index);
	if (it == mapChunkImages.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);	// Image*	// Image 동적할당 해제
	mapChunkImages.erase(it);		// 맵에서 노드 삭제
}
