#pragma once
#ifndef VY_STRING_H_
#define VY_STRING_H_

namespace vstl
{
	class String
	{
	public:
        //Constructor
        String();
        String(const char* c_str);
        String(String& string);

        //Destructor
        ~String();

        //Operator
        bool operator==(const String& rhand)const;
        bool operator>(const String& rhand)const;
        bool operator<(const String& rhand)const;
        String& operator=(const String& rhand);
    protected:
    private:
		size_tp m_Size;
		const char* m_CStr;
	};
}
#endif
