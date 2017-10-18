#ifndef __AUS_VOTE_H__
#define __AUS_VOTE_H__

#include <string>
#include <vector>
#include <map>

struct Candidate {
	std::string name;
	int votes;

	Candidate(){}
	Candidate(std::string name_, int votes_) : name(name_), votes(votes_) {}
};

struct Voter {
	int index;
	int *vote;
};

class AusVoteSystem {
public:
	AusVoteSystem(const std::vector<std::string>& candidate_names);
	~AusVoteSystem();

	bool AddVote(const std::vector<int>& vote);

	typedef std::vector<Candidate> RoundResult;
	std::vector<RoundResult> ComputeResult() const;

private:
	std::vector<std::string> candidates;
	std::vector<int*> votes;
};


#endif
