# -*- coding: gbk -*-
"""
Dijkstra算法的完整Python实现（GBK编码版本）
包含多种实现方式和实际应用示例
"""

import heapq
import time
import random
from typing import Dict, List, Tuple, Optional
from collections import defaultdict

class Dijkstra:
    """Dijkstra算法的主类"""
    
    def __init__(self, graph: Optional[Dict] = None):
        """
        初始化
        
        Args:
            graph: 图的邻接表表示 {节点: {邻居: 权重}}
        """
        self.graph = graph if graph is not None else {}
        self.distances = {}
        self.previous = {}
        self.visited = set()
        
    def add_edge(self, u, v, weight, directed=False):
        """添加边到图中"""
        if u not in self.graph:
            self.graph[u] = {}
        self.graph[u][v] = weight
        
        if not directed:  # 如果是无向图，添加反向边
            if v not in self.graph:
                self.graph[v] = {}
            self.graph[v][u] = weight
            
    def add_edges(self, edges: List[Tuple], directed=False):
        """批量添加边"""
        for u, v, weight in edges:
            self.add_edge(u, v, weight, directed)
            
    def reset(self):
        """重置算法状态"""
        self.distances = {}
        self.previous = {}
        self.visited = set()
    
    # ==================== 核心算法实现 ====================
    
    def naive_dijkstra(self, start):
        """
        朴素实现 - 使用数组，时间复杂度O(V?)
        适合稠密图或小规模图
        """
        self.reset()
        
        # 初始化所有距离为无穷大
        for node in self.graph:
            self.distances[node] = float('inf')
        self.distances[start] = 0
        
        nodes = list(self.graph.keys())
        
        while nodes:
            # 找到未访问节点中距离最小的
            current_node = None
            min_distance = float('inf')
            
            for node in nodes:
                if self.distances[node] < min_distance:
                    min_distance = self.distances[node]
                    current_node = node
            
            if current_node is None:  # 所有可达节点已处理
                break
                
            nodes.remove(current_node)
            self.visited.add(current_node)
            
            # 更新邻居节点的距离
            for neighbor, weight in self.graph.get(current_node, {}).items():
                if neighbor not in self.visited:
                    new_distance = self.distances[current_node] + weight
                    if new_distance < self.distances[neighbor]:
                        self.distances[neighbor] = new_distance
                        self.previous[neighbor] = current_node
        
        return self.distances, self.previous
    
    def heap_dijkstra(self, start):
        """
        堆优化实现 - 使用优先队列，时间复杂度O((V+E)logV)
        适合稀疏图
        """
        self.reset()
        
        # 初始化
        for node in self.graph:
            self.distances[node] = float('inf')
        self.distances[start] = 0
        
        # 使用优先队列（最小堆）
        heap = [(0, start)]
        
        while heap:
            current_distance, current_node = heapq.heappop(heap)
            
            # 如果已经找到更短路径，跳过
            if current_distance > self.distances[current_node]:
                continue
                
            self.visited.add(current_node)
            
            # 遍历邻居
            for neighbor, weight in self.graph.get(current_node, {}).items():
                if neighbor not in self.visited:
                    new_distance = current_distance + weight
                    
                    if new_distance < self.distances[neighbor]:
                        self.distances[neighbor] = new_distance
                        self.previous[neighbor] = current_node
                        heapq.heappush(heap, (new_distance, neighbor))
        
        return self.distances, self.previous
    
    # ==================== 辅助方法 ====================
    
    def get_path(self, start, end):
        """根据前驱节点重建路径"""
        if end not in self.previous:
            return None, float('inf')
            
        path = []
        current = end
        
        while current is not None:
            path.append(current)
            current = self.previous.get(current)
            
        path.reverse()
        
        if path[0] != start:
            return None, float('inf')
            
        total_distance = self.distances[end]
        return path, total_distance
    
    def get_all_paths(self, start):
        """获取从起点到所有节点的路径"""
        paths = {}
        for node in self.distances:
            if self.distances[node] < float('inf'):
                path, _ = self.get_path(start, node)
                paths[node] = path
        return paths
    
    def print_path(self, start, end):
        """打印路径信息"""
        path, distance = self.get_path(start, end)
        
        if path:
            print(f"从 {start} 到 {end} 的最短路径:")
            print(f"  路径: {' -> '.join(str(node) for node in path)}")
            print(f"  总距离: {distance}")
        else:
            print(f"无法找到从 {start} 到 {end} 的路径")
    
    def print_all_distances(self, start):
        """打印所有距离"""
        print(f"从 {start} 到各节点的最短距离:")
        for node, dist in sorted(self.distances.items()):
            if dist < float('inf'):
                print(f"  {start} -> {node}: {dist}")
            else:
                print(f"  {start} -> {node}: 不可达")
    
    # ==================== 文本可视化 ====================
    
    def print_graph(self):
        """以文本形式打印图结构"""
        print("图结构:")
        print("-" * 30)
        for u in self.graph:
            neighbors = self.graph[u]
            if neighbors:
                neighbor_str = ', '.join(f"{v}({weight})" for v, weight in neighbors.items())
                print(f"{u}: {neighbor_str}")
            else:
                print(f"{u}: 无邻居")
        print("-" * 30)
    
    def print_distance_table(self, start):
        """打印距离表"""
        print(f"\n从 {start} 出发的距离表:")
        print("节点\t距离\t路径")
        print("-" * 40)
        
        for node in sorted(self.distances.keys()):
            dist = self.distances[node]
            path, _ = self.get_path(start, node)
            
            if dist < float('inf'):
                path_str = ' -> '.join(str(p) for p in path) if path else "无路径"
                print(f"{node}\t{dist}\t{path_str}")
            else:
                print(f"{node}\t∞\t不可达")
    
    # ==================== 性能测试 ====================
    
    @staticmethod
    def generate_random_graph(num_nodes, num_edges, max_weight=100):
        """生成随机图"""
        graph = {}
        
        # 确保图是连通的
        nodes = list(range(num_nodes))
        for i in range(num_nodes - 1):
            u = i
            v = i + 1
            weight = random.randint(1, max_weight)
            if u not in graph:
                graph[u] = {}
            graph[u][v] = weight
            
            if v not in graph:
                graph[v] = {}
            graph[v][u] = weight
        
        # 添加额外的随机边
        for _ in range(num_edges - (num_nodes - 1)):
            u = random.randint(0, num_nodes - 1)
            v = random.randint(0, num_nodes - 1)
            if u != v:
                weight = random.randint(1, max_weight)
                if u not in graph:
                    graph[u] = {}
                graph[u][v] = weight
                
                if v not in graph:
                    graph[v] = {}
                graph[v][u] = weight
        
        return graph
    
    def benchmark(self, start, num_runs=10):
        """性能基准测试"""
        print(f"性能测试 (运行{num_runs}次取平均)")
        print("=" * 50)
        
        # 测试朴素实现
        total_time = 0
        for _ in range(num_runs):
            self.reset()
            start_time = time.time()
            self.naive_dijkstra(start)
            total_time += time.time() - start_time
        avg_time = total_time / num_runs
        print(f"朴素实现 (O(V?)): {avg_time:.6f} 秒")
        
        # 测试堆优化实现
        total_time = 0
        for _ in range(num_runs):
            self.reset()
            start_time = time.time()
            self.heap_dijkstra(start)
            total_time += time.time() - start_time
        avg_time = total_time / num_runs
        print(f"堆优化实现 (O((V+E)logV)): {avg_time:.6f} 秒")


# ==================== 实际应用示例 ====================

def example_city_navigation():
    """城市导航示例"""
    print("=" * 60)
    print("城市导航系统 - Dijkstra算法应用")
    print("=" * 60)
    
    # 创建城市地图
    dijkstra = Dijkstra()
    
    # 添加城市间的距离（公里）
    cities = [
        ("北京", "上海", 1200),
        ("北京", "广州", 2100),
        ("上海", "广州", 1500),
        ("上海", "成都", 1800),
        ("广州", "成都", 1600),
        ("广州", "深圳", 150),
        ("深圳", "香港", 50),
        ("成都", "西安", 700),
        ("西安", "北京", 1100),
        ("上海", "南京", 300),
        ("南京", "武汉", 500),
        ("武汉", "广州", 900)
    ]
    
    for city1, city2, distance in cities:
        dijkstra.add_edge(city1, city2, distance)
    
    # 用户输入起点和终点
    start_city = "北京"
    end_city = "香港"
    
    print(f"\n查找从 {start_city} 到 {end_city} 的最短路径...")
    
    # 显示图结构
    dijkstra.print_graph()
    
    # 运行算法
    print("\n正在计算最短路径...")
    distances, previous = dijkstra.heap_dijkstra(start_city)
    
    # 获取路径
    path, total_distance = dijkstra.get_path(start_city, end_city)
    
    if path:
        print(f"\n最短路径找到！总距离: {total_distance} 公里")
        print("=" * 40)
        
        # 显示详细路径信息
        print("详细路线:")
        for i in range(len(path) - 1):
            from_city = path[i]
            to_city = path[i+1]
            distance = dijkstra.graph[from_city][to_city]
            print(f"  {from_city} -> {to_city}: {distance} 公里")
        
        # 显示所有城市距离
        print(f"\n从 {start_city} 到其他城市的距离:")
        for city in ["上海", "广州", "成都", "西安", "南京", "武汉", "深圳", "香港"]:
            if city in dijkstra.distances:
                dist = dijkstra.distances[city]
                if dist < float('inf'):
                    print(f"  {start_city} -> {city}: {dist} 公里")
    else:
        print(f"\n无法找到从 {start_city} 到 {end_city} 的路径")
    
    return dijkstra, path


def example_network_routing():
    """网络路由示例"""
    print("\n" + "=" * 60)
    print("网络路由系统 - Dijkstra算法应用")
    print("=" * 60)
    
    # 创建网络拓扑
    dijkstra = Dijkstra()
    
    # 路由器之间的延迟（毫秒）
    network = [
        ("Router1", "Router2", 10),
        ("Router1", "Router3", 15),
        ("Router2", "Router3", 5),
        ("Router2", "Router4", 20),
        ("Router3", "Router5", 30),
        ("Router4", "Router5", 10),
        ("Router4", "Router6", 25),
        ("Router5", "Router6", 15)
    ]
    
    for router1, router2, delay in network:
        dijkstra.add_edge(router1, router2, delay)
    
    # 显示网络拓扑
    print("网络拓扑结构:")
    dijkstra.print_graph()
    
    # 查找最短路径
    start_router = "Router1"
    end_router = "Router6"
    
    print(f"\n查找从 {start_router} 到 {end_router} 的最低延迟路径...")
    
    distances, previous = dijkstra.heap_dijkstra(start_router)
    path, total_delay = dijkstra.get_path(start_router, end_router)
    
    if path:
        print(f"\n最低延迟路径找到！总延迟: {total_delay} ms")
        print("=" * 40)
        print(f"路径: {' -> '.join(path)}")
        
        # 显示路由表
        print(f"\n{start_router} 的路由表:")
        dijkstra.print_distance_table(start_router)
    
    return dijkstra, path


def example_game_pathfinding():
    """游戏寻路示例"""
    print("\n" + "=" * 60)
    print("游戏寻路系统 - Dijkstra算法应用")
    print("=" * 60)
    
    # 创建游戏地图（网格形式）
    dijkstra = Dijkstra()
    
    # 定义网格位置
    # 使用坐标表示位置，如 (0,0), (0,1) 等
    
    # 创建 5x5 网格地图
    grid_size = 5
    
    # 添加相邻网格的连接（不同地形有不同的移动成本）
    terrain_costs = {
        '草地': 1,      # 草地
        '森林': 2,     # 森林
        '山地': 3,     # 山地
        '水域': 999    # 水域（几乎不可通过）
    }
    
    # 随机生成地形
    terrain_grid = {}
    terrain_names = ['草地', '森林', '山地', '草地']  # 草地出现概率更高
    for x in range(grid_size):
        for y in range(grid_size):
            terrain = random.choice(terrain_names)
            terrain_grid[(x, y)] = terrain
    
    # 添加边（四方向移动）
    for x in range(grid_size):
        for y in range(grid_size):
            current = (x, y)
            
            # 检查四个方向
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < grid_size and 0 <= ny < grid_size:
                    neighbor = (nx, ny)
                    # 计算移动成本（取两个位置的平均成本）
                    terrain1 = terrain_grid[current]
                    terrain2 = terrain_grid[neighbor]
                    cost1 = terrain_costs[terrain1]
                    cost2 = terrain_costs[terrain2]
                    total_cost = (cost1 + cost2) / 2
                    
                    dijkstra.add_edge(current, neighbor, total_cost)
    
    # 设置起点和终点
    start_pos = (0, 0)
    end_pos = (grid_size-1, grid_size-1)
    
    print(f"从 {start_pos} 到 {end_pos} 的寻路...")
    print("地形类型: 草地(1), 森林(2), 山地(3), 水域(999)")
    
    # 运行算法
    distances, previous = dijkstra.heap_dijkstra(start_pos)
    path, total_cost = dijkstra.get_path(start_pos, end_pos)
    
    if path:
        print(f"\n找到路径！总移动成本: {total_cost:.2f}")
        
        # 打印地图
        print("\n地图 (S=起点, E=终点, #=路径, .=其他):")
        for y in range(grid_size-1, -1, -1):
            row = []
            for x in range(grid_size):
                pos = (x, y)
                if pos == start_pos:
                    row.append('S')
                elif pos == end_pos:
                    row.append('E')
                elif pos in path:
                    row.append('#')
                else:
                    # 显示地形首字符
                    terrain = terrain_grid[pos]
                    row.append(terrain[0])
            print(' '.join(row))
        
        # 显示路径详细
        print(f"\n路径详细 (共{len(path)}步):")
        for i, pos in enumerate(path):
            terrain = terrain_grid[pos]
            cost = terrain_costs[terrain]
            print(f"  第{i+1}步: {pos} ({terrain}, 成本: {cost})")
        
        # 显示地形成本
        print("\n地形成本说明:")
        for terrain, cost in terrain_costs.items():
            if cost < 100:  # 不显示水域（成本太高）
                print(f"  {terrain}: {cost}")
    
    return dijkstra, path


def performance_comparison():
    """性能比较示例"""
    print("\n" + "=" * 60)
    print("不同规模图的性能比较")
    print("=" * 60)
    
    # 测试不同规模的图
    sizes = [50, 100, 200, 500]
    
    for size in sizes:
        print(f"\n测试 {size} 个节点的图:")
        
        # 生成随机图
        edges = size * 2  # 平均每个节点2条边
        graph = Dijkstra.generate_random_graph(size, edges)
        
        dijkstra = Dijkstra(graph)
        
        # 随机选择一个起点
        start = random.choice(list(graph.keys()))
        
        # 运行一次获取结果（不包括第一次的编译时间）
        dijkstra.heap_dijkstra(start)
        
        # 基准测试
        dijkstra.benchmark(start, num_runs=3)


# ==================== 主函数 ====================

def main():
    """主函数"""
    print("Dijkstra算法完整Python实现 (GBK编码版本)")
    print("=" * 70)
    print("作者: Python助手")
    print("功能: 包含多种实现、性能测试和应用示例")
    print("=" * 70)
    
    while True:
        print("\n请选择示例:")
        print("1. 基本使用示例")
        print("2. 城市导航系统")
        print("3. 网络路由系统")
        print("4. 游戏寻路系统")
        print("5. 性能比较测试")
        print("6. 交互式模式")
        print("0. 退出")
        
        choice = input("\n请输入选择 (0-6): ").strip()
        
        if choice == '1':
            print("\n1. 基本使用示例")
            print("-" * 40)
            
            # 创建一个简单的图
            dijkstra = Dijkstra()
            
            # 添加边
            dijkstra.add_edge('A', 'B', 4)
            dijkstra.add_edge('A', 'C', 2)
            dijkstra.add_edge('B', 'C', 1)
            dijkstra.add_edge('B', 'D', 5)
            dijkstra.add_edge('C', 'D', 8)
            dijkstra.add_edge('C', 'E', 10)
            dijkstra.add_edge('D', 'E', 2)
            dijkstra.add_edge('D', 'F', 6)
            dijkstra.add_edge('E', 'F', 3)
            
            # 显示图结构
            dijkstra.print_graph()
            
            # 运行算法
            start_node = 'A'
            print(f"\n计算从节点 {start_node} 出发的最短路径...")
            
            # 使用堆优化版本
            distances, previous = dijkstra.heap_dijkstra(start_node)
            
            # 显示结果
            dijkstra.print_all_distances(start_node)
            
            # 获取到特定节点的路径
            end_node = 'F'
            dijkstra.print_path(start_node, end_node)
            
            # 显示距离表
            dijkstra.print_distance_table(start_node)
            
        elif choice == '2':
            example_city_navigation()
            
        elif choice == '3':
            example_network_routing()
            
        elif choice == '4':
            example_game_pathfinding()
            
        elif choice == '5':
            performance_comparison()
            
        elif choice == '6':
            interactive_mode()
            
        elif choice == '0':
            print("\n感谢使用Dijkstra算法演示程序！")
            print("再见！")
            break
            
        else:
            print("无效选择，请重新输入")


def interactive_mode():
    """交互式模式"""
    print("\n" + "=" * 50)
    print("交互式Dijkstra算法演示")
    print("=" * 50)
    
    dijkstra = Dijkstra()
    
    while True:
        print("\n选择操作:")
        print("1. 添加边")
        print("2. 运行Dijkstra算法")
        print("3. 显示当前图")
        print("4. 查找特定路径")
        print("5. 显示距离表")
        print("6. 重置图")
        print("0. 返回主菜单")
        
        choice = input("请输入选择 (0-6): ").strip()
        
        if choice == '1':
            try:
                u = input("输入起始节点: ").strip()
                v = input("输入目标节点: ").strip()
                weight = float(input("输入权重: ").strip())
                directed = input("是否是有向边？(y/n): ").lower() == 'y'
                
                dijkstra.add_edge(u, v, weight, directed)
                print(f"边 {u} - {v} (权重: {weight}) 已添加")
            except ValueError:
                print("输入错误！请确保权重是数字")
        
        elif choice == '2':
            if not dijkstra.graph:
                print("图是空的！请先添加边")
                continue
                
            start = input("输入起始节点: ").strip()
            
            if start not in dijkstra.graph:
                print(f"节点 {start} 不存在于图中")
                continue
                
            print("\n选择算法版本:")
            print("1. 朴素实现 (O(V?))")
            print("2. 堆优化实现 (O((V+E)logV))")
            
            algo_choice = input("请输入选择 (1-2): ").strip()
            
            if algo_choice == '1':
                distances, previous = dijkstra.naive_dijkstra(start)
                print("朴素实现完成")
            elif algo_choice == '2':
                distances, previous = dijkstra.heap_dijkstra(start)
                print("堆优化实现完成")
            else:
                print("无效选择，使用堆优化实现")
                distances, previous = dijkstra.heap_dijkstra(start)
                
            # 显示结果
            dijkstra.print_all_distances(start)
        
        elif choice == '3':
            if not dijkstra.graph:
                print("图是空的")
            else:
                dijkstra.print_graph()
        
        elif choice == '4':
            if not dijkstra.distances:
                print("请先运行Dijkstra算法")
                continue
                
            start = input("输入起始节点: ").strip()
            end = input("输入目标节点: ").strip()
            
            dijkstra.print_path(start, end)
        
        elif choice == '5':
            if not dijkstra.distances:
                print("请先运行Dijkstra算法")
                continue
                
            start = input("输入起始节点: ").strip()
            dijkstra.print_distance_table(start)
        
        elif choice == '6':
            dijkstra = Dijkstra()
            print("图已重置")
        
        elif choice == '0':
            print("返回主菜单")
            break
        
        else:
            print("无效选择，请重新输入")


# ==================== 快速测试函数 ====================

def quick_test():
    """快速测试函数"""
    print("快速测试Dijkstra算法...")
    
    # 创建简单的图
    d = Dijkstra()
    d.add_edge('A', 'B', 4)
    d.add_edge('A', 'C', 2)
    d.add_edge('B', 'C', 1)
    d.add_edge('B', 'D', 5)
    d.add_edge('C', 'D', 8)
    
    # 运行算法
    distances, previous = d.heap_dijkstra('A')
    
    print(f"从 A 到各节点的距离:")
    for node, dist in distances.items():
        if dist < float('inf'):
            print(f"  A -> {node}: {dist}")
    
    # 测试路径
    path, total = d.get_path('A', 'D')
    if path:
        print(f"\nA到D的路径: {' -> '.join(path)}")
        print(f"总距离: {total}")


# ==================== 运行程序 ====================

if __name__ == "__main__":
    print("正在启动Dijkstra算法演示程序...")
    
    # 快速测试
    # quick_test()
    
    # 运行主程序
    main()