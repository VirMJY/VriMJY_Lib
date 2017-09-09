/*************************************************/
/*				Others functions implement		 */
/*************************************************/

namespace vstl
{
    size_tp Strlen(const char* _Str)
    {
        if(!_Str)
            return 0;

        size_tp size = 0;
        while(_Str[size] != '\0')
        {
            ++size;
        }

        return size;
    }
}