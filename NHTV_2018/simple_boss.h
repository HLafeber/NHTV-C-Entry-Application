// simple_boss.h
//

#ifndef LZZ_simple_boss_h
#define LZZ_simple_boss_h
#define LZZ_INLINE inline
class Enemy
{
public:
	int m_Damage;
	Enemy();
	void Attack() const;
};
class Boss : public Enemy
{
public:
	int m_DamageMultiplier;
	Boss();
	void SpecialAttack() const;
};
int SBmain();
#undef LZZ_INLINE
#endif
