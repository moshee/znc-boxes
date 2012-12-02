bool CTable::GetLine(unsigned int uIdx, CString& sLine) const {
    stringstream ssRet;

    if (empty()) {
        return false;
    }

    string left, middle, right, bar;

    switch (uIdx) {
    case 1:
        ssRet.fill(' ');
        ssRet << "\u2502 ";

        for (unsigned int a = 0; a < m_vsHeaders.size(); a++) {
            ssRet.width(GetColumnWidth(a));
            ssRet << std::left << m_vsHeaders[a];
            ssRet << ((a == m_vsHeaders.size() -1) ? " \u2502" : " \u2502 ");
        }

        sLine = ssRet.str();
        return true;

    case 0:
        left   = "\u250c\u2500";
        middle = "\u2500\u252c\u2500";
        right  = "\u2500\u2510";
        bar    = "\u2500";
        break;

    case 2:
        left   = "\u255e\u2550";
        middle = "\u2550\u256a\u2550";
        right  = "\u2550\u2561";
        bar    = "\u2550";
        break;

    default:
        if (uIdx == (size() + 3)) {
            left   = "\u2514\u2500";
            middle = "\u2500\u2534\u2500";
            right  = "\u2500\u2518";
            bar    = "\u2500";
            break;
        }
        uIdx -= 3;

        if (uIdx < size()) {
            const vector<CString>& mRow = (*this)[uIdx];
            ssRet.fill(' ');
            ssRet << "\u2502 ";

            for (unsigned int c = 0; c < m_vsHeaders.size(); c++) {
                ssRet.width(GetColumnWidth(c));
                ssRet << std::left << mRow[c];
                ssRet << ((c == m_vsHeaders.size() -1) ? " \u2502" : " \u2502 ");
            }

            sLine = ssRet.str();
            return true;
        } else {
            return false;
        }
    }

    ssRet << left;

    for (unsigned int a = 0; a < m_vsHeaders.size(); a++) {
        int w = GetColumnWidth(a);
        // fill it manually instead of using stringstream::fill()
        for (int i = 0; i < w; i++) {
            ssRet << bar;
        }
        ssRet << ((a == m_vsHeaders.size() -1) ? right : middle);
    }

    sLine = ssRet.str();

    return true;
}
