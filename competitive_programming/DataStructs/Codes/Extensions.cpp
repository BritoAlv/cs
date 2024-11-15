template <typename T, typename A> int arg_max(std::vector<T, A> const &vec)
{
    return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A> int arg_min(std::vector<T, A> const &vec)
{
    return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

template <typename T, typename A> T sum(std::vector<T, A> const &vec)
{
    return std::accumulate(vec.begin(), vec.end(), T{});
}