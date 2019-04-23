// game_lobby.h
//

#ifndef LZZ_game_lobby_h
#define LZZ_game_lobby_h
#define LZZ_INLINE inline
#include <ostream>

class Player
{
public:
  Player (std::string const & name = "");
	std::string GetName () const;
  Player * GetNext () const;
  void SetNext (Player * next);
private:
	std::string m_Name;
  Player * m_pNext;
};
class Lobby
{
  friend std::ostream & operator << (std::ostream & os, Lobby const & aLobby);
public:
  Lobby ();
  ~ Lobby ();
  void AddPlayer ();
  void RemovePlayer ();
  void Clear ();
private:
  Player * m_pHead;
};

std::ostream & operator << (std::ostream & os, Lobby const & aLobby);
int glmain ();
#undef LZZ_INLINE
#endif
