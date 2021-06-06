function levelp1(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,0,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,false,0.0,false,10.0,false,0.0)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png","Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,0,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,true,10.0,true,15.0,false,0.0)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,0,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,true,10.0,true,20.0,true,15.0)
	SetScene("Level3")
  end
end

function levelp2(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,6,6,"Data/Qbert.png",true,true)
	AddPlayer("Level1",2,6,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,false,0.0,false,8.0,false,0.0)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png","Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,6,6,"Data/Qbert.png",true,true)
	AddPlayer("Level2",2,6,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,true,5.0,true,8.0,false,0.0)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"Data/Tiles/CubeYellow.png","Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,6,6,"Data/Qbert.png",true,true)
	AddPlayer("Level3",2,6,0,"Data/Qbert.png",true,true)
	SetLevelDifficulty(true,5.0,true,8.0,true,16.0,true,20.0)
	SetScene("Level3")
  end
end

function levelvs(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,0,0,"Data/Qbert.png",true,true)
	AddPlayer("Level1",2,1,0,"Data/Coily.png",false,false)
	SetLevelDifficulty(false,0.0,false,0.0,true,12.0,false,0.0)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"Data/Tiles/CubeYellow.png","Data/Tiles/CubePurple.png","Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,0,0,"Data/Qbert.png",true,true)
	AddPlayer("Level2",2,1,0,"Data/Coily.png",false,false)
	SetLevelDifficulty(false,0.0,true,12.0,true,20.0,false,0.0)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"Data/Tiles/CubeYellow.png","Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,0,0,"Data/Qbert.png",true,true)
	AddPlayer("Level3",2,1,0,"Data/Coily.png",false,false)
	SetLevelDifficulty(false,0.0,true,12.0,true,20.0,true,25.0)
	SetScene("Level3")
  end
end

function menu(i)
	CreateScene("Menu")
	CreateMenu("Menu")
	SetScene("Menu")
end

menu()

gameMode = "levelp1"
level = 1
