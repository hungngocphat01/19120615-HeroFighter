#include "Team.h"

void Team::InsertNewMember(string data)
{
	Hero* newhero = Hero::CreateNewHero(data);
	// Cập nhật lại điểm số cho từng cặp hero mỗi khi thêm vào
	for (Hero*& member : members) {
		newhero->UpdtPntsInTeam(*member);
	}
	members.push_back(newhero);
}

void Team::UpdateEnvironment(attribute_t env)
{
	for (Hero*& member : members) {
		member->UpdtPntsBsdOnEnvrnmnt(env);
	}
}
