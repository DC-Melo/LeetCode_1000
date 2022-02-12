define plistnode
    set $_node = (ListNode*)$arg0
    while $_node
        printf "value is %d\n", $_node->val
        set $_node = $_node->next
    end
end

document dump_list
    This is a command to dump all elements in Linked List
    arg0 is the head
end
# define find                             
#     set $ptr = $arg0
#     set $cnt = 0
#     while ( ($ptr<=$arg1) && ($cnt<$arg2) )
#         if ( *(unsigned int *)$ptr == $arg3 )
#             x /wx $ptr
#             set $cnt = $cnt + 1
#         end
#         set $ptr = $ptr + 4
#     end
# end
 
#
# std::LinkNode<>
#

# define pLinkNode
# set $x=$args0
# while $x--
# p head->val
# set head=(head->next)
# end
# end

# define pListNode
# 	if $argc == 0
# 		help pLinkNode
# 	else
# 		set ListNode $pcurrent = $arg0
# 		while pcurrent != ((void *) 0)
#             p pcurrent->val
#             set pcurrent=(pcurrent->next)
# 		end
# 	end
# end
# document pListNode
# 	to list the list by travel 
# end
