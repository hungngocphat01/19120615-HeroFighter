#include "Team.h"

void Team::UpdateEnvironment(attribute_t env)
{
	for (Hero*& member : members) {
		member->UpdtPntsBsdOnEnvrnmnt(env);
	}
}
