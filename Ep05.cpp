template <typename Container>
Container& myFunction(Container& container)
{
    static_assert(std::is_integral_v<typename Container::value_type>, "An integer type is required here");
    if (container.empty())
    {
        return container;
    }
    
    auto max = *std::max_element(container.begin(), container.end());
    auto min = *std::min_element(container.begin(), container.end());

    std::vector<std::vector<typename Container::value_type>> hashedValues;
    hashedValues.resize(max - min + 1);

    for (auto e : container)
    {
        auto hash = e % (max + 1);
        auto& sameHash = hashedValues[hash];
        sameHash.push_back(e);
    }

    container.clear();
    for (auto sameHash : hashedValues)
    {
        for (auto e : sameHash)
        {
            container.push_back(e); 
        }
    }

    return container;
}
