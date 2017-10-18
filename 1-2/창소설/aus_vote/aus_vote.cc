#include "aus_vote.h"
#include <iostream>

using namespace std;

AusVoteSystem::AusVoteSystem(const std::vector<std::string>& candidate_names) {
/* implement here*/
	candidates.clear();
	votes.clear();
	candidates = candidate_names;
}

AusVoteSystem::~AusVoteSystem() {
	/* implement here*/
	for(int i = 0; i < votes.size(); i++){
		delete votes[i];
	}
}

bool AusVoteSystem::AddVote(const std::vector<int>& vote) {
	/* implement here*/
	votes.push_back(new int[vote.size()]);
	for(int i = 0; i < votes.size(); i++){
		*(votes[votes.size() - 1] + i) = vote[i];
	}
	return true;
}

// int hasPerfectWinner(const Candidate *candidateList, map<int, bool> &erased, int candidateSize, int voterSize) {
// 	/* implement here*/
// }

// int hasHalfWinner(const Candidate *candidateList, map<int, bool> &erased, int candidateSize, int voterSize, int start) {
// 	/* implement here*/
// }

vector<AusVoteSystem::RoundResult> AusVoteSystem::ComputeResult() const {
	/* implement here*/
	vector<AusVoteSystem::RoundResult> roundresult;
	vector<int> loser;
	vector<Voter> voters;

	for(int i = 0; i < votes.size(); i++){
		Voter temp;
		temp.index = 0;
		temp.vote = votes[i];
		voters.push_back(temp);
	}

	while(true){
		AusVoteSystem::RoundResult roundresult_;

		for(int i = 0; i < candidates.size(); i++){
			roundresult_.push_back(Candidate(candidates[i], 0));
		}

		for(int i = 0; i < voters.size(); i++){
			if(voters[i].index >= candidates.size()) continue;
			roundresult_[voters[i].vote[voters[i].index] - 1].votes++;
		}

		vector<int> deleted;
		int a = 0;
		for(int i = 0; i < roundresult_.size(); i++){
			bool is = false;
			for(int j = 0; j < loser.size(); j++){
				if(a == loser[j]) is = true;
			}
			if(is){
				roundresult_.erase(roundresult_.begin() + i);
				i--;
				deleted.push_back(a);
			}
			a++;
		}

		int mininum = 1024;
		for(int i = 0; i < roundresult_.size(); i++){
			bool is = false;
			for(int j = 0; j < loser.size(); j++){
				int temp = i;
				for(int j = 0; j < deleted.size(); j++){
					if(deleted[j] <= temp) temp++;
				}
				if(loser[j] == temp) is = true;
			}
			if(mininum > roundresult_[i].votes) mininum = roundresult_[i].votes;
		}

		for(int i = 0; i < roundresult_.size(); i++){
			if(roundresult_[i].votes == mininum){
				int temp = i;
				for(int j = 0; j < deleted.size(); j++){
					if(deleted[j] <= temp) temp++;
				}
				loser.push_back(temp);
			}
		}

		for(int i = 0; i < voters.size(); i++){
			while(true){
				bool ok = false;
				for(int j = 0; j < loser.size(); j++){
					if(voters[i].vote[voters[i].index] - 1 == loser[j]) ok = true;
				}
				if(ok == true) voters[i].index++;
				else 
					break;
			}
		}

		roundresult.push_back(roundresult_);
		if(roundresult[roundresult.size() - 1].size() < 1) break;
		if(roundresult[roundresult.size() - 2].size() == 1){
			int size_ = roundresult[roundresult.size() - 2].size();
			int max = 0;
			for(int i = 0; i < size_; i++){
				if(max < roundresult[roundresult.size() - 2][i].votes) 
					max = roundresult[roundresult.size() - 2][i].votes;
			}
			if(max < (double)voters.size() / 2){
				roundresult.push_back(roundresult_);
				break;
			}
			break;
		}
	}

	return roundresult;
}
