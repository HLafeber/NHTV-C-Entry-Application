/**
 *	NHTV2018, simple_boss.cpp
 *	Purpose: Demonstrates inheritance
 *	
 *	@author(s) Harley Lafeber
 *	@version 0.1.001 (Game version, Code version, File version)
 *	@since 21/01/2018 15:00
 */

//Includes
#include "stdafx.h"
#include <iostream>
#include "NHTV_2018.h"
using namespace std;

///<summary>
///Base enemy class used for attacking the player
///</summary>
class Enemy
{
public:
	int m_Damage;

	Enemy();
	void Attack() const;
};
//Base damage
Enemy::Enemy() :
	m_Damage(10)
{}
//Base attack
void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}
///<summary>
///Base boss class, inherited from the enemy class
///</summary>
class Boss : public Enemy
{
public:
	int m_DamageMultiplier;

	Boss();
	void SpecialAttack() const;

};
//Deinfe Damage multiplyer
Boss::Boss() :
	m_DamageMultiplier(3)
{}
//Spepcial attack function
void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points!\n";
}

///<summary>
///Main RPG Boss Loop
///</summary>
int SBmain()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();
	
	main();
	return 0;
}