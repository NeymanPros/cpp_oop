#pragma once

class MatrixS {
private:
	std::pair<ptrdiff_t, ptrdiff_t> size = { 0, 0 };
	int* data = nullptr;
public:

	MatrixS() {};

	explicit MatrixS(std::pair<ptrdiff_t, ptrdiff_t> _size = {0, 0}) {
		size = { 0, 0 };
	}

	MatrixS(ptrdiff_t i, ptrdiff_t j) {
		try {
			if (i < 0 || j < 0) {
				throw std::invalid_argument("Negative size!");
			}
			size = { i, j };
			delete[] data;
			data = new int[i * j];
		}
		catch (std::exception& m) {
			std::cerr << m.what() << "\n";
		}
	}

	MatrixS(const std::pair<int, int> _size) {
		try {
			if (_size.first < 0) {
				throw std::invalid_argument("Negative size!");
			}
			if (_size.second < 0) {
				throw std::invalid_argument("Negative size!");
			}
			size = _size;
			if (_size.first * _size.second) {
				delete[] data;
				data = new int[_size.first * _size.second];
			}
		}
		catch (std::exception& _size) {
			std::cerr << _size.what() << "\n";
		}
	}

	MatrixS(const MatrixS& m) {
		delete[] data;
		data = new int[m.nCols() * m.nRows()];
		std::copy(m.data, m.data + m.size.first * m.size.second, data);
		size = m.size;
	}

	~MatrixS() {
		delete[] data;
	}

	void operator=(const MatrixS& m) {
		delete[] data;
		data = new int[m.nCols() * m.nCols()];
		size = m.size;
		std::copy(m.data, m.data + m.size.first * m.size.second, data);
	}

	[[nodiscard]] int& at(std::pair<ptrdiff_t, ptrdiff_t> pp) {
		try {
			if (pp.first < 0 || pp.second < 0 || pp.first > size.first || pp.second > size.second) {
				throw std::out_of_range("Out of range!");
			}
			return *(data + pp.first * size.second + pp.second);
		}
		catch (std::exception& pp) {
			std::cerr << pp.what() << "\n";
		}
	}

	[[nodiscard]] const int& at(std::pair<ptrdiff_t, ptrdiff_t> pp) const {
		try {
			if (pp.first < 0 || pp.second < 0 || pp.first > size.first || pp.second > size.second) {
				throw std::out_of_range("Out of range!");
			}
			return *(data + pp.first * size.second + pp.second);
		}
		catch (std::exception& pp) {
			std::cerr << pp.what() << "\n";
		}
	}

	[[nodiscard]] int& at(const ptrdiff_t i, const ptrdiff_t j) {
		try {
			if (i < 0 || j < 0 || i > size.first || j > size.second) {
				throw std::out_of_range("Out of range!");
			}
			return *(data + i * size.second + j);
		}
		catch (std::exception& pp) {
			std::cerr << pp.what() << "\n";
		}
	}

	[[nodiscard]] const int& at(const ptrdiff_t i, const ptrdiff_t j) const {
		try {
			if (i < 0 || j < 0 || i > size.first || j > size.second) {
				throw std::out_of_range("Out of range!");
			}
			return *(data + i * size.second + j);
		}
		catch (std::exception& pp) {
			std::cerr << pp.what() << "\n";
		}
	}

	void resize(std::pair<ptrdiff_t, ptrdiff_t> pp) {
		try {
			if (pp.first < 0 || pp.second < 0) {
				throw std::invalid_argument("Negative size!");
			}

			int* temp = new int[size.first * size.second];
			std::copy(data, data + size.first * size.second, temp);
			delete[] data;
			data = new int[pp.first * pp.second];

			int f = size.first;
			int s = size.second;

			size.first = pp.first;
			size.second = pp.second;

			for (int a = 0; a < pp.first && a < f; a++) {
				for(int b = 0; b < pp.second && b < s; b++){
					this->at(a, b) = *(temp + a * s + b);
				}
			}

			delete[] temp;
		}
		catch (std::exception& pp) {
			std::cerr << pp.what() << "\n";
		}
	}

	void resize(const ptrdiff_t i, const ptrdiff_t j) {
		try {
			if (i < 0 || j < 0) {
				throw std::invalid_argument("Negative size!");
			}

			int* temp = new int[size.first * size.second];
			std::copy(data, data + size.first * size.second, temp);
			delete[] data;
			data = new int[i * j];

			int f = size.first;
			int s = size.second;

			size.first = i;
			size.second = j;

			for (int a = 0; a < i && a < f; a++) {
				for (int b = 0; b < j && b < s; b++) {
					this->at(a, b) = *(temp + a * s + b);
				}
			}

			delete[] temp;
		}
		catch (std::exception& i) {
			std::cerr << i.what() << "\n";
		}
	}

	[[nodiscard]] const std::pair<ptrdiff_t, ptrdiff_t> ssize() const noexcept{
		return size;
	}

	[[nodiscard]] std::ptrdiff_t nRows() const noexcept{
		return size.first;
	}

	[[nodiscard]] std::ptrdiff_t nCols() const noexcept {
		return size.second;
	}
};