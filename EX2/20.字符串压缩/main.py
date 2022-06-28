import requests

cookies = {
    'JSESSIONID': 'C0A3A6EC8D406918F483317543132F44',
}

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'Accept-Language': 'en-US,en;q=0.9',
    'Cache-Control': 'max-age=0',
    # 'Content-Length': '192',
    # 'Content-Type': 'multipart/form-data; boundary=----WebKitFormBoundaryNiJn59n8C68ejNbX',
    # 'Cookie': 'JSESSIONID=C0A3A6EC8D406918F483317543132F44',
    'Origin': 'http://202.197.98.89',
    'Proxy-Connection': 'keep-alive',
    'Referer': 'http://202.197.98.89/assignment/programList.jsp?proNum=20&assignID=799',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36',
}

params = {
    'problemID': '13024',
    'assignID': '799',
    'doSubmit': 'true',
    'progLanguage': 'python',
    'wtime': '106',
}

response = requests.post('http://202.197.98.89/assignment/showProcessMsg.jsp', params=params, cookies=cookies, headers=headers, verify=False)
print(response.text)