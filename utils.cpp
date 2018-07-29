#include "utils.h"

Utils::Utils()
{

}

/**
 * @brief Utils::isDouble 是否是偶数
 * @param c 待验证
 * @return bool
 */
bool Utils::isDouble(int c)
{
    return c % 2 == 0 ? true : false;
}
