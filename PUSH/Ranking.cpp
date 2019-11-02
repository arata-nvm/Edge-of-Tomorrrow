#include "Ranking.h"

Ranking::Ranking(String _fileName) {
	fileName = _fileName;
}

int Ranking::addScore(int score) {
	ranks.emplace_back(score);
	ranks.sort();
	return getRank(score);
}

int Ranking::getRank(int score) {
	return 1;
}

int Ranking::getHighScore() {
	return ranks[0];
}

Array<int> Ranking::getScores(int numToGet) {
	if (ranks.size() < numToGet) {
		return Range(0, numToGet).asArray();
	}
	Array<int> scores;
	for (int i = 0; i < numToGet; i++) {
		scores << ranks[i];
	}
	return scores;
}

int Ranking::size() {
	return ranks.size();
}

void Ranking::saveRanking() {
	TextWriter writer(fileName, OpenMode::Trunc, TextEncoding::UTF8);
	for (const auto& rank : ranks) {
		writer.writeln(rank);
	}
	writer.close();
}

void Ranking::loadRanking() {
	ranks.clear();
	TextReader reader(fileName);
	Optional<String> line;
	while (line = reader.readLine()) {
		ranks.emplace_back(Parse<int32>(line.value()));
	}
	reader.close();
	ranks.sort();
}
