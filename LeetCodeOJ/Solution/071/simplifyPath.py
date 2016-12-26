class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        newPath = ''
        pathList = []
        for dir in path.strip('/').split('/'):
            if dir == '' or dir == '.':
                continue
            if dir == '..' and pathList:
                pathList.pop()
            if dir != '..':
                pathList.append(dir)
        for dir in pathList:
            newPath += '/' + dir
        return newPath if newPath else '/'
            
                