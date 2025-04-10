/*
   constants.hpp -- Hyperdrive's global constants.

   Copyright 2025 by Sylvain Nieuwlandt (for Kingdom of Dreams)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef HD_CONSTANTS_HPP
#define HD_CONSTANTS_HPP

namespace HD {
   typedef int Result;

   namespace Codes {
      constexpr Result OK             = 0;
      constexpr Result INVALID_ARG    = 1;
      constexpr Result PLATFORM_ERROR = 2;
      constexpr Result RENDERER_ERROR = 3;
   }; // namespace Codes
}; // namespace HD

#endif // HD_CONSTANTS_HPP