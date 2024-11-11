template <typename T, typename A> int arg_max(std::vector<T, A> const &vec)
{
    return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}
