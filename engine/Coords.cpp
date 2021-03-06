#include "Coords.h"

bool CheckRow(char row) noexcept {
    return 'A' <= row && row <= 'H';
};

bool CheckCol(char col) noexcept {
    return 1 <= col && col <= 8;
}

Coords::Coords(char row, char col) noexcept {
    SetRow(row);
    SetCol(col);
}

char Coords::GetRow() const noexcept {
    return _row;
}

char Coords::GetCol() const noexcept {
    return _col;
}

int Coords::GetRowIndex() const noexcept {
    return _row - 'A';
}

int Coords::GetColIndex() const noexcept {
    return _col - 1;
}
void Coords::SetCol(char col) noexcept {
    if (CheckCol(col)) {
        _col = col;
    } else {
        _col = 0;
    }
}

void Coords::SetRow(char row) noexcept {
    if (CheckRow(row)) {
        _row = row;
    } else {
        _col = 0;
    }
}

std::string Coords::ToString() const noexcept {
    std::string s;
    s.push_back(_row); s.push_back(_col);
    return s;
}

std::ostream& operator << (std::ostream& out, const Coords& coords) {
    return out << coords.GetRow() << coords.GetCol();
}

