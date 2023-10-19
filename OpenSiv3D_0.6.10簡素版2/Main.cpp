# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Bullet.h"
#include <vector>

using std::vector;

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.0,0.0,0.0});
	TextureAsset::Register(U"BULLET", U"8.png");

	Bullet* b = nullptr;
	vector<Bullet*> Gun;
	while (System::Update())
	{
		if (KeySpace.down()) {
			b = new Bullet(Vec2{ Scene::Width() / 2,Scene::Height() });
			Gun.push_back(b);
		}
		for (int i = 0; i < Gun.size(); i++)
			Gun[i]->Update();
		for (int i = 0; i < Gun.size(); i++)
			Gun[i]->Draw();
		Print << Gun.size();
		//vector<Bullet*>::iterator theI;
		//for (theI = Gun.begin(); theI != Gun.end();)
		//{
		//	if ((*theI)->isAlive_ == false) {
		//		delete* theI;//箱の中身＝Bulletそのもの
		//		theI = Gun.erase(theI); //箱自体
		//	}
		//	else
		//		theI++;
		//}


	}
}


