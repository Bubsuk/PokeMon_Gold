#pragma once



enum class eDir
{
    Idle, Up, Left, Down, Right
};

enum class eCharacter
{
    Mom, Doctor_O, Osub, Nurse, Master, SubMaster, Mart
};

enum class eTerrain
{   
    Open = 0,           // 통과가능
    Grass = 1,          // 포켓몬 출현
    Close = 2,          // 못지나감
    Door = 3,           // 문 1개
    BottomBlock = 4,    // 아래막힘
    RightBlock = 5,     // 오른쪽막힘
    LeftBlock = 6,      // 왼쪽막힘
};

enum class ePokemon
{
    Caterpie,
    Ggorat,
    Pika,
    Chicorita, Bcane, Riaco, 
    Alligay,
};

enum class ePokemonType
{
    Bug,
    Butterfly,
    Bird,
    Etc,
    BigBird,
    Pika
};

enum class Item
{
    Heal,
    Antidote,
    Paralysis,
    TreeFruit,
    AntiFruit
};

enum class SkillType
{
    Normal,
    Fire,
    Water,
    Grass,
    Flying,
    Bug

};

enum class Gender
{
    Male, Female
};

