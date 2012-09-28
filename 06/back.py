
# def prefix_func(s):
#     prefix = []
#     for i in range(len(s)):
#         temp = s[:i+1]
#         k = 0
#         for i in range(len(temp)-1):
#             if temp[:i+1] == temp[-(i+1):] and k < len(temp):
#                 k = i+1
#         prefix[len(prefix):] = [k]
#     return prefix
