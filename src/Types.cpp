//Implementation include
#include "Types.hpp"

//Include Windows
#include "IncludeWindows.hpp"

namespace yam
{

	std::wstring toWideString(DefaultString& str)
	{
        //Accepted answer from: https://stackoverflow.com/questions/6691555/converting-narrow-string-to-wide-string
        if(str.empty())    return std::wstring();

        // determine required length of new string
        size_t reqLength = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int) str.length(), 0, 0);

        // construct new string of required length
        std::wstring ret(reqLength, L'\0');

        // convert old string to new string
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int) str.length(), &ret[0], (int) ret.length());

        // return new string ( compiler should optimize this away )
        return ret;
	}

}