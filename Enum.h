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
    Open = 0,           // �������
    Grass = 1,          // ���ϸ� ����
    Close = 2,          // ��������
    Door = 3,           // �� 1��
    BottomBlock = 4,    // �Ʒ�����(����)
    RightBlock = 5,     // �����ʸ���(����)
    LeftBlock = 6,      // ���ʸ���(����)
};

enum class ePokemon
{
    Caterpie,
    Ggorat,
    Pika,
    Chicorita, Bcane, Riaco, 
    Alligay,
    /*Jangcro, Dandegi, Butter, Bbul, Ddak,
    DokChung, Gugu, Pigeon, PigeonTwo,
    Ggaebi, Ggaebidrill, Richu, Bayleaf,
    Meganium, Rat*/
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

// ���ϸ� ���� : �� �� ���� ȥ�� ȭ��
