//
// Created by sashi0034 on 2022/06/18.
//

#ifndef FILL_TILES_UNIQUECOLLECTION_H
#define FILL_TILES_UNIQUECOLLECTION_H

#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

using std::unique_ptr;

namespace gameEngine
{
    template<typename T> class UniqueCollection
    {
        std::vector<std::unique_ptr<T>> m_Pool{};
        int currentProcessingIndex = 0;

        typename std::vector<unique_ptr<T>>::iterator findIterator(T* target)
        {
            assert(!m_Pool.empty());
            assert(currentProcessingIndex < int(m_Pool.size()));

            if (target == m_Pool[currentProcessingIndex].get()) return m_Pool.begin() + currentProcessingIndex;

            auto iter = std::find_if(
                    m_Pool.begin(), m_Pool.end(),
                    [target](unique_ptr<T> child) {
                        return child.get() == target;
                    });

            return iter;
        }

        void collectGarbage(std::vector<int> &upwardIndexes)
        {
            for (int i = upwardIndexes.size() - 1; i >= 0; --i)
            {
                int index = upwardIndexes[i];
                m_Pool.erase(m_Pool.begin() + index);
            }
        }
    public:
        T* Birth(T* child)
        {
            auto product = std::shared_ptr<T>(child);
            m_Pool.push_back(product);
            return product;
        };
        void Register(unique_ptr<T> child)
        {
            m_Pool.template emplace_back(child);
        };
        bool Reset(T* oldChild, T* newChild)
        {
            if (m_Pool.empty()) return false;

            auto iter = findIterator(oldChild);

            if (iter==m_Pool.end()) return false;

            *iter->reset(newChild);

            return true;
        }
        void ProcessEach(std::function<void(T*)> process)
        {
            int size =m_Pool.size();
            std::vector<int> garbage{};

            for (int i = 0; i < size; ++i)
            {
                currentProcessingIndex = i;
                if (m_Pool[i] != nullptr)
                    process(m_Pool[i]);
                else
                    garbage.push_back(i);
            }

            currentProcessingIndex = 0;
            collectGarbage(garbage);
        }
        void Release()
        {
            m_Pool = std::vector<unique_ptr<T>>{};
        }
        ~UniqueCollection()
        {
            assert(m_Pool.size()==0);
        }
    };
}


#endif //FILL_TILES_UNIQUECOLLECTION_H
